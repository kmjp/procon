#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll W;
int S,K;
pair<ll,ll> D[200][200][32];
pair<ll,ll> from[200][200];
pair<ll,ll> to[200][200];

pair<ll,ll> comp(pair<ll,ll> A,pair<ll,ll> B) {
	if(A.second<-1LL<<59||B.second<-1LL<<59) return {-1LL<<60,-1LL<<60};
	return {A.first+B.first,max(A.second+B.first,B.second)};
}
pair<ll,ll> par(pair<ll,ll> A,pair<ll,ll> B) {
	if(A.second<-1LL<<59) return B;
	if(B.second<-1LL<<59) return A;
	return {max(A.first,B.first),max(A.second,B.second)};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>W>>S>>K;
	S--;
	FOR(x,N) FOR(y,N) FOR(i,32) D[x][y][i]={-1LL<<60,-1LL<<60};
	FOR(i,M) {
		cin>>x>>y>>r;
		D[x-1][y-1][0]={(ll)r,max((ll)r,0LL)};
	}
	FOR(i,30) {
		FOR(x,N) FOR(y,N) FOR(r,N) D[x][r][i+1]=par(D[x][r][i+1],comp(D[x][y][i],D[y][r][i]));
	}
	
	FOR(x,N) FOR(y,N) from[x][y]={-1LL<<60,-1LL<<60};
	FOR(x,N) from[x][x]={0,0};
	FOR(i,30) if(K&(1<<i)) {
		FOR(x,N) FOR(y,N) to[x][y]={-1LL<<60,-1LL<<60};
		FOR(x,N) FOR(y,N) FOR(r,N) to[x][r]=par(to[x][r],comp(from[x][y],D[y][r][i]));
		swap(from,to);
	}
	
	ll ret=-1LL<<60;
	FOR(x,N) ret=max(ret,max(W+from[S][x].first,from[S][x].second));
	
	if(ret<-1LL<<59) ret=-1;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
