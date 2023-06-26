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
ll A[1010101],D[101010];
vector<int> E[101010];
const ll mo=998244353;

int NV[101010];
ll dp[101010];
ll ret;
ll p10[11];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void dfs(int cur,int pre) {
	dp[cur]=1;
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[cur]+=dp[e];
		NV[cur]+=NV[e];
	}
	dp[cur]=dp[cur]%mo*p10[D[cur]]%mo;
	return;
}

void dfs2(int cur,int pre,ll par) {
	dp[cur]=dp[cur]*modpow(p10[D[cur]])%mo;
	(ret+=(N-NV[cur])*dp[cur]%mo*A[cur])%=mo;
	(dp[cur]+=par)%=mo;
	(ret+=dp[cur]%mo*A[cur])%=mo;
	
	FORR(e,E[cur]) if(e!=pre) {
		ll d=(dp[cur]-dp[e]+mo)*p10[D[cur]]%mo;
		(ret+=(dp[cur]-dp[e])*(NV[e])%mo*A[cur])%=mo;
		dfs2(e,cur,d);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	for(i=1;i<=10;i++) p10[i]=p10[i-1]*10%mo;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		A[i]=atoll(s.c_str())%mo;
		D[i]=s.size();
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	dfs2(0,0,0);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
