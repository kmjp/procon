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


int N,K;
ll B[303030],SB[303030];
vector<int> E[303030];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
int U[303030],V[303030];

int id;
int L[303030],R[303030],P[303030];

void dfs(int cur,int pre) {
	P[cur]=pre;
	L[cur]=id++;
	SB[cur]=B[cur];
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		SB[cur]+=SB[e];
	}
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>x;
		B[x-1]=1;
	}
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	dfs(0,0);
	
	ll ret=0;
	ll r2=(mo+1)/2;
	FOR(i,N-1) {
		int cur=U[i];
		int par=V[i];
		if(L[cur]<L[par]) swap(cur,par);
		assert(P[cur]==par);
		
		ll a=B[par];
		ll b=B[cur];
		
		// par->cur
		ll tot=1;
		ret+=a*(mo+1-b)%mo*r2%mo*(SB[cur]+1)%mo*(K-(SB[cur]+1))%mo;
		// cur->par
		ret+=(mo+1-a)*b%mo*r2%mo*(SB[cur]-1)%mo*(K-(SB[cur]-1))%mo;
		//‚»‚êˆÈŠO
		tot-=a*(mo+1-b)%mo*r2%mo;
		tot-=b*(mo+1-a)%mo*r2%mo;
		tot=(tot%mo+mo)%mo;
		(ret+=tot*SB[cur]%mo*(K-SB[cur])%mo)%=mo;
		ret=(ret%mo+mo)%mo;
		
		
		
		
		a=(a+b)*r2%mo;
		B[par]=B[cur]=a;
	}
	ret=(ret%mo+mo)%mo;
	ll a=1LL*K*(K-1)/2%mo;
	ret=ret*modpow(a)%mo;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
