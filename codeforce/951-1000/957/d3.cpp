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

int T,N,M,K;
string A;

int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K>>A;
		A="L"+A+"L";
		N+=2;
		FOR(i,N+3) dp[i]=-1;
		dp[0]=K;
		FOR(i,N) {
			if(A[i]=='L') {
				for(j=1;j+i<N&&j<=M;j++) {
					if(A[i+j]=='L') dp[i+j]=max(dp[i+j],dp[i]);
					if(A[i+j]=='W') dp[i+j]=max(dp[i+j],dp[i]);
				}
			}
			else if(A[i]=='W') {
				if(A[i+1]=='L') dp[i+1]=max(dp[i+1],dp[i]-1);
				if(A[i+1]=='W') dp[i+1]=max(dp[i+1],dp[i]-1);
			}
		}
		if(dp[N-1]>=0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
