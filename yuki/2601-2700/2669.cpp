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
ll dp[1<<24];
ll A[25];
int G[303030];


ll comb(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*(P_--)/i;
	
	return p;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>s;
		x=0;
		FOR(j,N) if(s[j]=='1') x|=1<<j;
		dp[x]++;
	}
	
	for(i=K;i<=N;i++) {
		A[i]=1;
		for(j=K;j<i;j++) A[i]-=A[j]*comb(i,j);
	}
	
	int mask;
	FOR(i,N) FOR(mask,1<<N) if(mask&(1<<i)) dp[mask^(1<<i)]+=dp[mask];
	FOR(mask,1<<N) dp[mask]*=A[__builtin_popcount(mask)];
	FOR(i,N) FOR(mask,1<<N) if(mask&(1<<i)) dp[mask]+=dp[mask^(1<<i)];
	FOR(i,M+1) G[i]=1<<20;
	
	FOR(mask,1<<N) chmin(G[dp[mask]],__builtin_popcount(mask));
	
	for(i=M-1;i>=0;i--) chmin(G[i],G[i+1]);
	
	for(i=1;i<=M;i++) cout<<G[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
