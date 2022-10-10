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
int C[2525];
ll V[2525];

ll dp[2525][2525];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i+1]>>V[i+1];
	FOR(x,2522) FOR(y,2522) dp[x][y]=-1LL<<60;
	dp[0][0]=0;
	for(i=N;i>0;i--) {
		int maxn=N/i;
		
		for(int n=0;n<=maxn;n++) {
			for(int w=0;w<=N;w++) {
				if(n&&w>=i) break;
				deque<pair<int,ll>> Q;
				int cn=n;
				int cw=w;
				while(cn<=maxn&&cw<=N) {
					while(Q.size()&&cn-Q.front().first>C[i]) Q.pop_front();
					ll add=dp[cn][cw]+V[i]*(2500-cn);
					if(Q.size()) {
						dp[cn][cw]=max(dp[cn][cw],Q.front().second-V[i]*(2500-cn));
					}
					while(Q.size()&&Q.back().second<=add) Q.pop_back();
					Q.push_back({cn,add});
					cn++;
					cw+=i;
				}
			}
		}
	}
	
	for(i=1;i<=N;i++) {
		ll ma=-1LL<<60;
		FOR(x,N+1) ma=max(ma,dp[i][x]);
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
