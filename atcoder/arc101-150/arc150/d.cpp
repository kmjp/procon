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

const ll mo=998244353;
int N;
int P[202020];
vector<int> E[202020];
int C[202020];
ll dp[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur) {
	C[cur]=1;
	FORR(e,E[cur]) {
		C[cur]+=dfs(e);
	}
	
	dp[cur]=modpow(C[cur]);
	FORR(e,E[cur]) {
		dp[cur]+=dp[e];
	}
	dp[cur]%=mo;
	
	
	return C[cur];
}

ll F[202020];
int D[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=201010;i++) {
		(F[i]=F[i-1]+modpow(i))%=mo;
	}
	ll ret=0;
	D[0]=1;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		P[i]--;
		D[i]=D[P[i]]+1;
		ret+=F[D[i]];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
