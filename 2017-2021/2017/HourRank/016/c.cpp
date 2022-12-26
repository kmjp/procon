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

ll pat[5050][5050];
int N;
vector<pair<int,int>> E[5050];
int C[5050];
int L[5050];
int R[5050];
ll ret;
ll mo=1000000009;
ll fact[5050],rev[5050];


void dfs(int cur,int pre,int d,int* V) {
	
	V[d]++;
	FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,d+1,V);
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	fact[0]=1;
	for(i=1;i<=5005;i++) {
		fact[i]=fact[i-1]*i%mo;
		rev[i]=modpow(i);
	}
	
	FOR(i,N) FORR(r,E[i]) if(r.first<i) {
		ZERO(L);
		ZERO(R);
		dfs(i,r.first,1,L);
		dfs(r.first,i,1,R);
		
		for(x=1;L[x];x++) for(y=1;R[y];y++) {
			ret+=L[x]*R[y]*fact[N]%mo*2*rev[x+y]%mo*r.second%mo;
		}
		
	}
	
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
