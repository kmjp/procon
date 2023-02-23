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

ll P,K;
ll mo;

ll modpow(ll a, ll n = mo-2, ll m=mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%m,a=a*a%m,n>>=1;
	return r;
}

int totient(int v) {
	int ret=v;
	for(int i=2;i*i<=v;i++) if(v%i==0) {
		ret=ret/i*(i-1);
		while(v%i==0) v/=i;
	}
	if(v>1) ret=ret/v*(v-1);
	return ret;
}

int mod_root(int p,int a) { // x^p=a mod mo
	vector<int> D;
	for(int i=2;i*i<=mo-1;i++) if((mo-1)%i==0) D.push_back(i),D.push_back((mo-1)/i);
	int g=2;
	while(1) {
		int ng=0;
		FORR(d,D) if(modpow(g,d)==1) ng=1;
		if(ng==0) break;
		g++;
	}
	
	ll cur=a;
	int rg=modpow(g);
	int mstep=sqrt(mo);
	map<int,int> M;
	int i;
	FOR(i,mstep+3) {
		M[cur]=i;
		cur=cur*rg%mo;
	}
	ll pg=modpow(g,mstep);
	int x=-1,step=0;
	cur=1;
	while(x==-1) {
		if(M.count(cur)) x=step+M[cur];
		M[cur]=step;
		cur=cur*pg%mo;
		step+=mstep;
	}
	// g^x=a‚È‚Ì‚Åg^(p*q)=g^x=a‚Æ‚µ‚Äq=x/p (mod mo-1) mo-1‚Í‡¬”‚È‚Ì‚ÅGCD‚ÅŠ„‚Á‚Ä‘Î‰ž
	int tmo=mo-1;
	int gcd=__gcd(tmo,p);
	if(x%gcd) return -1;
	tmo/=gcd;
	x/=gcd;
	p/=gcd;
	return modpow(g,1LL*x*modpow(p,totient(tmo)-1,tmo)%tmo);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	K=(P-1)/2;
	ll a=((-4*K*K-16*K+1)%P+P)%P;
	
	mo=P;
	x=mod_root(2,a);
	if(x==-1) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
