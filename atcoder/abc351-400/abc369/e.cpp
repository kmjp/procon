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

int N;
int M;
ll U[202020],V[202020],T[202020];
ll E[404][404];
int Q;

ll dp[32][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) E[x][y]=(x==y)?0:(1LL<<60);
	FOR(i,M) {
		cin>>U[i]>>V[i]>>T[i];
		U[i]--,V[i]--;
		E[U[i]][V[i]]=E[V[i]][U[i]]=min(E[U[i]][V[i]],T[i]);
	}
	FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	
	cin>>Q;
	while(Q--) {
		int K;
		int B[5];
		cin>>K;
		ll sum=0;
		FOR(i,K) {
			cin>>B[i];
			B[i]--;
			sum+=T[B[i]];
		}
		int mask;
		FOR(mask,1<<5) FOR(i,10) dp[mask][i]=1LL<<60;
		FOR(i,K) {
			dp[1<<i][i*2]=E[0][V[B[i]]];
			dp[1<<i][i*2+1]=E[0][U[B[i]]];
		}
		FOR(mask,1<<K) FOR(i,2*K) if(dp[mask][i]<1LL<<60) {
			FOR(x,K) if((mask&(1<<x))==0) {
				y=(i%2)?V[B[i/2]]:U[B[i/2]];
				chmin(dp[mask|(1<<x)][2*x],dp[mask][i]+E[y][V[B[x]]]);
				chmin(dp[mask|(1<<x)][2*x+1],dp[mask][i]+E[y][U[B[x]]]);
			}
		}
		ll ret=1LL<<60;
		FOR(i,K) {
			ret=min(ret,dp[(1<<K)-1][2*i]+E[U[B[i]]][N-1]);
			ret=min(ret,dp[(1<<K)-1][2*i+1]+E[V[B[i]]][N-1]);
		}
		cout<<ret+sum<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
