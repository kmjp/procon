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

const ll mo=998244353;
ll N;
ll dp[500][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	dp[0][0]=dp[1][0]=1;
	for(i=0;i<=N;i++) { //Œ»ó‚Ì‘˜a
		for(j=1;j*j<=N;j++) { //Œ„ŠÔ‚Ì”
			if(i+1+2*(j+1)<N+10) {
				//Œ„ŠÔ•s•Ï
				(dp[j][i+2*j]+=dp[j][i])%=mo;
				//Œ„ŠÔ‚ð–„‚ß‚é
				(dp[j-1][i+1+2*(j-1)]+=j*dp[j][i])%=mo;
				(dp[j+0][i+1+2*(j+0)]+=2*j*dp[j][i])%=mo;
				(dp[j+1][i+1+2*(j+1)]+=j*dp[j][i])%=mo;
			}
		}
	}
	ll ret=0;
	FOR(i,N+1) if(i%2==N%2) ret+=dp[0][i];
	
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
