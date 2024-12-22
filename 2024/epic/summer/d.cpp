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

int T,N,A[5050];
int dp[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		FOR(i,N) {
			cin>>x;
			M[x]++;
		}
		vector<int> V;
		FORR2(a,b,M) V.push_back(b);
		N=V.size();
		FOR(x,N+2) FOR(y,N+2) dp[x][y]=100000;
		dp[0][0]=0;
		FOR(i,N) {
			int v=V[i];
			FOR(j,N+1) {
				if(j+v<=N&&j>0) dp[i+1][j]=min(dp[i][j-1]+1,dp[i][j+v]);
				else if(j+v<=N) dp[i+1][j]=dp[i][j+v];
				else if(j>0) dp[i+1][j]=dp[i][j-1]+1;
				
			}
		}
		int ret=1000000;
		FOR(i,N+1) ret=min(ret,dp[N][i]);
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
