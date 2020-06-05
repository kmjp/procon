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

int N,K;
vector<int> E[1010];
const ll mo=1000000007;
ll dp[1010][1010];
int C[1010];
ll ret;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


int dfs(int cur,int pre) {
	int i;
	C[cur]=1;
	FOR(i,K) dp[cur][i]=1;
	FORR(e,E[cur]) if(e!=pre) {
		C[cur]+=dfs(e,cur);
		ll sum=0;
		FOR(i,K) {
			(sum+=dp[e][i])%=mo;
			(dp[cur][i]*=sum)%=mo;
		}
	}
	return C[cur];
}

void dfs2(int cur,int pre,vector<ll> P) {
	ll sum=0;
	int i;
	if(pre==-1) {
		FOR(i,K) ret+=dp[cur][i];
	}
	else {
		FOR(i,K) {
			(ret+=dp[cur][i]*sum)%=mo;
			(sum+=P[i])%=mo;
		}
		sum=0;
		FOR(i,K) {
			(sum+=P[i])%=mo;
			(dp[cur][i]*=sum)%=mo;
		}
	}
	
	FORR(e,E[cur]) if(e!=pre) {
		sum=0;
		FOR(i,K) {
			(sum+=dp[e][i])%=mo;
			P[i]=dp[cur][i]*modpow(sum)%mo;
		}
		dfs2(e,cur,P);
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	vector<ll> P(K);
	
	dfs2(0,-1,P);
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
