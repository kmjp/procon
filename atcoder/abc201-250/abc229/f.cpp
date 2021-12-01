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
int A[202020],B[202020];
ll dp[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll tot=0;
	FOR(i,N) {
		cin>>A[i];
		tot+=A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		tot+=B[i];
	}
	
	ll ret=-1LL<<60;
	FOR(x,2) {
		if(x==0) {
			dp[0][0]=0;
			dp[0][1]=-1LL<<60;
		}
		else {
			dp[0][0]=-1LL<<60;
			dp[0][1]=A[0];
		}
		for(i=1;i<N;i++) {
			dp[i][0]=max(dp[i-1][1]+B[i-1],dp[i-1][0]);
			dp[i][1]=max(dp[i-1][0]+A[i]+B[i-1],dp[i-1][1]+A[i]);
		}
		if(x==0) {
			ret=max(ret,dp[N-1][0]);
			ret=max(ret,dp[N-1][1]+B[N-1]);
		}
		else {
			ret=max(ret,dp[N-1][0]+B[N-1]);
			ret=max(ret,dp[N-1][1]);
		}
	}
	cout<<tot-ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
