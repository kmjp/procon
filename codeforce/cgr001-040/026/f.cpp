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

int T,N;
ll M,B[2020];
const ll mo=998244353;
string S;
ll dp[2020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>S;
		S="P"+S+"S";
		FOR(i,N) cin>>B[i+1];
		B[0]=B[N+1]=0;
		N+=2;
		
		ll ret=0;
		set<ll> sum;
		FOR(i,N-1) sum.insert(B[i]+B[i+1]);
		FORR(s,sum) {
			FOR(i,N) dp[i][0]=dp[i][1]=-1;
			dp[0][0]=1;
			for(i=1;i<N;i++) {
				int CP=(S[i]!='S'),CS=(S[i]!='P');
				
				//PP,SS;
				if(abs(B[i]-B[i-1])<=M) {
					if(dp[i-1][0]!=-1&&CP) (dp[i][0]=dp[i-1][0])%=mo;
					if(dp[i-1][1]!=-1&&CS) (dp[i][1]=dp[i-1][1])%=mo;
				}
				// PS
				if(dp[i-1][0]!=-1&&CS&&B[i]+B[i-1]==s) {
					if(dp[i][1]==-1) dp[i][1]=0;
					(dp[i][1]+=dp[i-1][0])%=mo;
				}
				// SP
				if(dp[i-1][1]!=-1&&CP&&(abs(B[i]+B[i-1]-s)+1)/2<=M) {
					if(dp[i][0]==-1) dp[i][0]=0;
					(dp[i][0]+=dp[i-1][1])%=mo;
				}
			}
			if(dp[N-1][1]>=0) ret+=dp[N-1][1];
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
