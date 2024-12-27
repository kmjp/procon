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

int T,N,K;
ll mo;

ll dp[4040][4040][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>mo;
		
		FOR(x,N+3) FOR(y,K+1) dp[x][y][0]=dp[x][y][1]=0;
		dp[0][0][0]=1;
		
		FOR(i,N+1) {
			ll s0=0,s1=0;
			FOR(x,K+1) {
				s0+=dp[i][x][0];
				s1+=dp[i][x][1];
			}
			s0%=mo;
			s1%=mo;
			
			ll ssa0=0,ssa1=0;
			ll ssb0=0,ssb1=0;
			if(i) {
				FOR(x,K+1) {
					(ssa0+=dp[i-1][x][0]*(K-x))%=mo;
					(ssa1+=dp[i-1][x][1]*(K-x))%=mo;
					(ssb0+=dp[i-1][x][0])%=mo;
					(ssb1+=dp[i-1][x][1])%=mo;
				}
			}
			
			FOR(j,K+1) {
				if(i==N&&j) continue;
				(dp[i+1][j][0]+=s0)%=mo;
				(dp[i+1][j][1]+=s1)%=mo;
				if(i) {
					ssb0+=mo-dp[i-1][K-j][0];
					ssb1+=mo-dp[i-1][K-j][1];
					(dp[i+1][j][0]+=ssa1)%=mo;
					(dp[i+1][j][1]+=ssa0)%=mo;
					(ssa0+=mo-ssb0)%=mo;
					(ssa1+=mo-ssb1)%=mo;
				}
			}
		}
		ll ret=dp[N+1][0][0]+mo-dp[N+1][0][1];
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
