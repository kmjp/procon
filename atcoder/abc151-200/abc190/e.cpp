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

int N,M,K;
int A[101010],B[101010];
int C[101010];
vector<int> E[101010];
ll D[17][101010];
ll dp[17][1<<17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	cin>>K;
	FOR(i,K) {
		cin>>C[i];
		C[i]--;
		FOR(j,N) D[i][j]=1LL<<40;
		queue<int> Q;
		D[i][C[i]]=0;
		Q.push(C[i]);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(D[i][e]>D[i][x]+1) {
				D[i][e]=D[i][x]+1;
				Q.push(e);
			}
		}
	}
	
	int mask;
	FOR(i,K) {
		FOR(mask,1<<K) dp[i][mask]=1LL<<40;
		dp[i][1<<i]=1;
	}
	FOR(mask,1<<K) {
		FOR(i,K) if(dp[i][mask]<1LL<<40) {
			FOR(j,K) if((mask&(1<<j))==0) {
				chmin(dp[j][mask|(1<<j)],dp[i][mask]+D[i][C[j]]);
			}
		}
	}
	ll ret=1LL<<40;
	FOR(i,K) ret=min(ret,dp[i][(1<<K)-1]);
	if(ret>=1LL<<40) ret=-1;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
