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

int N,A,B,P,Q;
const ll mo=998244353;
ll dp[101][101][2];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(int A,int B,int turn) {
	if(A>=N) return 1;
	if(B>=N) return 0;
	if(dp[A][B][turn]>=0) return dp[A][B][turn];
	
	ll ret=0;
	int i;
	if(turn==0) {
		for(i=1;i<=P;i++) ret+=hoge(A+i,B,1);
		ret=ret%mo*modpow(P)%mo;
	}
	else {
		for(i=1;i<=Q;i++) ret+=hoge(A,B+i,0);
		ret=ret%mo*modpow(Q)%mo;
	}
	return dp[A][B][turn]=ret%mo;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>P>>Q;
	MINUS(dp);
	cout<<hoge(A,B,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
