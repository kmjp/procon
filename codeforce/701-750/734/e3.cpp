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

int T;
int N,K;
int A[202020];
int nex[2020][2020];
int dp[2020][2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i];
		}
		FOR(i,N+1) nex[N][i]=N;
		for(i=N-1;i>=0;i--) {
			FOR(j,N+1) nex[i][j]=nex[i+1][j];
			nex[i][A[i]]=i;
		}
		
		FOR(x,N+2) FOR(y,N+2) dp[x][y]=N;
		dp[0][0]=-1;
		
		FOR(x,K) {
			int mi=N;
			for(y=0;y<=N;y++) {
				mi++;
				if(mi<N) dp[x+1][y]=nex[mi][y];
				mi=min(mi,dp[x][y]);
			}
		}
		int ret=1<<20;
		for(y=0;y<=N;y++) {
			if(dp[K][y]<N) ret=min(ret,dp[K][y]-y+1);
		}
		if(ret>=N) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
