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

int N,VV,L;
int X[2020],V[2020],W[2020];
ll from[2020];
ll to[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>VV>>L;
	FOR(i,N) {
		cin>>X[i+1]>>V[i+1]>>W[i+1];
	}
	X[N+1]=L;
	for(i=1;i<=N+1;i++) {
		int d=X[i]-X[i-1];
		FOR(y,2020) to[y]=1LL<<60;
		FOR(x,VV+1) if(x>=d) {
			to[x-d]=min(to[x-d],from[x]);
			to[min(VV,x-d+V[i])]=min(to[min(VV,x-d+V[i])],from[x]+W[i]);
		}
		swap(from,to);
	}
	
	ll mi=1LL<<60;
	FOR(x,VV+1) mi=min(mi,from[x]);
	if(mi==1LL<<60) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
