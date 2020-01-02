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
vector<int> E[201010];
int C[201010];
const ll mo=1000000007;
ll ret;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int pre) {
	C[cur]=1;
	vector<ll> B;
	FORR(e,E[cur]) if(e!=pre) {
		
		B.push_back(dfs(e,cur));
		C[cur]+=B.back();
	}
	if(C[cur]<N) B.push_back(N-C[cur]);
	
	ll P[3]={(mo+1)/2,0,0};
	FORR(b,B) {
		ll w=modpow((mo+1)/2,b);
		b=(1+mo-w)%mo;
		ll Q[3]={};
		Q[0]=P[0]*w%mo;
		Q[1]=(P[1]*w+P[0]*b)%mo;
		Q[2]=(P[2]+P[1]*b)%mo;
		swap(P,Q);
	}
	
	ret+=P[2];
	
	return C[cur];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
