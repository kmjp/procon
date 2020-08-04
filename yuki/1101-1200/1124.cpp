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
vector<int> E[302020];
const ll mo=1000000007;

ll A[303030],B[303030];
ll p2[303030],r2;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void dfs(int cur,int pre) {
	A[cur]=B[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll a=(A[cur]+A[cur]+A[e])*r2%mo;
		ll b=(B[cur]+B[cur]+B[e]+2*(A[cur]*A[e]))%mo*r2%mo;
		A[cur]=a;
		B[cur]=b;
	}
}

void dfs2(int cur,int pre, ll PA, ll PB) {
	ll a=(A[cur]+A[cur]+PA)*r2%mo;
	ll b=(B[cur]+B[cur]+PB+2*(A[cur]*PA))%mo*r2%mo;
	A[cur]=a;
	B[cur]=b;
	
	FORR(e,E[cur]) if(e!=pre) {
		ll XA=((A[cur]-A[e]*r2%mo)+mo)%mo;
		ll XB=((B[cur]-XA*A[e]%mo-B[e]*r2%mo)%mo+mo)%mo;
		dfs2(e,cur,XA,XB);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	r2=(mo+1)/2;
	p2[0]=1;
	FOR(i,300101) p2[i+1]=p2[i]*2%mo;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	dfs2(0,0,0,0);
	ll ret=0;
	FOR(i,N) ret+=B[i]*p2[N-1]%mo;
		
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
