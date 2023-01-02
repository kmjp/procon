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
ll mo;

ll dp[505][505];
ll p2[1202020];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	dp[1][1]=1;
	p2[0]=1;
	FOR(i,N*N) p2[i+1]=p2[i]*2%mo;
	
	for(i=1;i<=N-2;i++) {
		for(j=1;j<=N;j++) if(dp[i][j]) {
			ll p=p2[j]-1;
			ll kv=dp[i][j];
			for(k=1;i+k<N;k++) {
				kv=(kv*p)%mo;
				(dp[i+k][k]+=kv*comb(N-1-i,k)%mo*p2[k*(k-1)/2])%=mo;
			}
		}
	}
	ll ret=0;
	for(j=1;j<=N;j++) ret+=dp[N-1][j]*(p2[j]-1)%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
