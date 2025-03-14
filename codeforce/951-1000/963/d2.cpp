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
int A[502020];
int dp[505050];

int ok(int v) {
	int i;
	FOR(i,N+1) dp[i]=1<<30;
	if(N%K==0) {
		for(i=0;i<N;i+=K) dp[i+1]=A[i]<v;
	}
	else {
		dp[0]=0;
	}
	
	FOR(i,N) {
		if(i+K<=N) dp[i+K]=min(dp[i+K],dp[i]);
		dp[i+1]=min(dp[i+1],dp[i]+(A[i]<v));
	}
	int lef=N%K;
	if(lef==0) lef=K;
	if(lef%2) return dp[N]<=lef/2;
	return dp[N]<lef/2;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		if(K>N) K=N;
		FOR(i,N) cin>>A[i];
		
		if(K==1) {
			cout<<*max_element(A,A+N)<<endl;
			continue;
		}
		
		int ret=0;
		for(i=29;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
