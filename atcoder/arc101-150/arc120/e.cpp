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
ll A[202020];

int dp[202020];

int ok(ll v) {
	int i;
	ZERO(dp);
	dp[0]=1;
	dp[1]=-1;
	FOR(i,N-1) {
		if(i) dp[i]+=dp[i-1];
		if(dp[i]==0) continue;
		
		int x=lower_bound(A+i,A+N,A[i]+2*v+1)-A;
		x--;
		if(x==N-1) return 1;
		if(i==0) {
			dp[1]++;
			dp[x]--;
		}
		else if(x>i+2) {
			dp[i+2]++;
			dp[x]--;
		}
		
	}
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	ll mi=1LL<<29;
	for(i=28;i>=0;i--) if(ok(mi-(1<<i))) mi-=1<<i;
	
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
