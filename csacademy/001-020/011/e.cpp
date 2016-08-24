#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<int> E[101010];
int V[101010];
ll dp[101010];
ll fact[101010];
ll mo=1000000007;
ll ret;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void dfs(int cur,int pre) {
	ll pi=1;
	V[cur]=1;
	dp[cur]=1;
	
	FORR(r,E[cur]) if(r!=pre) {
		dfs(r,cur);
		dp[cur] = dp[cur] * dp[r] % mo;
		V[cur] += V[r];
		pi = pi * fact[V[r]] % mo;
	}
	
	dp[cur] = dp[cur] * fact[V[cur]-1] % mo * modpow(pi) % mo;
}

void dfs2(int cur,int pre,ll parent) {
	
	dp[cur] = dp[cur] * parent % mo * fact[N-1] % mo * modpow(fact[V[cur]-1]) % mo * modpow(fact[N-V[cur]]) % mo;
	ret += dp[cur];
	
	FORR(r,E[cur]) if(r!=pre) {
		ll v = dp[cur] * modpow(dp[r]) % mo;
		v = v * fact[V[r]] % mo * fact[N-(V[r]+1)] % mo * modpow(fact[N-1]) % mo;
		dfs2(r,cur,v);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=101000;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	dfs2(0, -1, 1);
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
