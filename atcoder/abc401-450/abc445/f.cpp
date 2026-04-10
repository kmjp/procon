#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,K;
ll C[101][101][32];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) cin>>C[y][x][0];
	
	FOR(i,30) {
		FOR(y,N) FOR(x,N) C[y][x][i+1]=1LL<<60;
		FOR(y,N) FOR(x,N) FOR(k,N) C[y][k][i+1]=min(C[y][k][i+1],C[y][x][i]+C[x][k][i]);
	}
	
	FOR(i,N) {
		ll from[101],to[101];
		FOR(j,N) from[j]=1LL<<60;
		from[i]=0;
		FOR(k,30) if(K&(1<<k)) {
			FOR(j,N) to[j]=1LL<<60;
			FOR(x,N) FOR(y,N) to[y]=min(to[y],from[x]+C[x][y][k]);
			swap(from,to);
		}
		cout<<from[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
