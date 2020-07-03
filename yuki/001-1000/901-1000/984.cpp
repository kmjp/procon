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

ll N,P,mo;

ll modpow(ll a, ll n = mo-2, ll mo=mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll modlog(int g,int a) {  // return g^x=a mod a
	map<int,int> M;
	ll cur=1;
	int sq=sqrt(mo);
	int i;
	FOR(i,sq) {
		M[cur]=i;
		cur=cur*g%mo;
	}
	
	ll step=cur;
	cur=1;
	ll num=0;
	int lp=0;
	while(1) {
		ll x=a*modpow(cur)%mo;
		if(lp++>sq+5) return 1LL<<50;
		if(M.count(x)) return num+M[x];
		cur=cur*step%mo;
		num+=sq;
	}
}

int get_prim(int p) { //primitive element of prime p
	int q=p-1;
	vector<int> V;
	ll x;
	for(x=2;x*x<=p;x++) if(q%x==0) V.push_back(x),V.push_back(q/x);
	
	for(x=2;;x++) {
		int ng=0;
		FORR(v,V) if(modpow(x,v,p)==1) {
			ng=1;
			break;
		}
		if(ng==0) return x;
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>P>>N;
	mo=P;
	if(N==1 || P==2) return _P("0\n");
	
	x=modlog(get_prim(P),N);
	cout<<x%2<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
