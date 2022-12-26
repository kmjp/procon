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
vector<pair<int,int>> E[10101];
int K;
int R[26];
int V[26];
ll dp[10101];
ll D[26][26];
int A[101010],B[101010],C[101010];

ll dp2[1<<12][12][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>R[i];
		R[i]--;
	}
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		
		E[A[i]].push_back({B[i],C[i]});
		E[B[i]].push_back({A[i],C[i]});
	}
	FOR(i,K) {
		V[i*2]=A[R[i]];
		V[i*2+1]=B[R[i]];
	}
	V[2*K+1]=N-1;
	
	FOR(i,2*K+2) {
		FOR(j,N) dp[j]=1LL<<60;
		priority_queue<pair<ll,int>> Q;
		dp[V[i]]=0;
		Q.push({0,V[i]});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FORR2(e,c,E[cur]) if(dp[e]>co+c) {
				dp[e]=co+c;
				Q.push({-dp[e],e});
			}
		}
		FOR(j,2*K+2) D[i][j]=dp[V[j]];
	}
	
	
	FOR(i,K) {
		FOR(x,1<<K) dp2[x][i][0]=dp2[x][i][1]=1LL<<60;
	}
	
	FOR(i,K) {
		dp2[(1<<i)][i][0]=D[i*2+1][2*K]+C[R[i]];
		dp2[(1<<i)][i][1]=D[i*2][2*K]+C[R[i]];
	}
	
	int mask;
	FOR(mask,1<<K) {
		FOR(x,K) if(mask&(1<<x)) {
			FOR(y,K) if((mask&(1<<y))==0) {
				chmin(dp2[mask|(1<<y)][y][0],dp2[mask][x][0]+D[x*2][y*2+1]+C[R[y]]);
				chmin(dp2[mask|(1<<y)][y][1],dp2[mask][x][0]+D[x*2][y*2]+C[R[y]]);
				chmin(dp2[mask|(1<<y)][y][0],dp2[mask][x][1]+D[x*2+1][y*2+1]+C[R[y]]);
				chmin(dp2[mask|(1<<y)][y][1],dp2[mask][x][1]+D[x*2+1][y*2]+C[R[y]]);
				
			}
		}
	}
	ll mi=1LL<<60;
	FOR(x,K) {
		mi=min(mi,dp2[(1<<K)-1][x][0]+D[x*2][2*K+1]);
		mi=min(mi,dp2[(1<<K)-1][x][1]+D[x*2+1][2*K+1]);
	}
	cout<<mi<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
