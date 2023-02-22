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

ll L,R,M;
ll mo;


map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	ll lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	
	ll v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll lucas_ex(ll n,ll r,ll p,ll q) { // C(n,r) % p^q
	const int NUM_=1400001;
	static ll fact[NUM_+1], pp, pq;

	if(n<0||r<0||r>n) return 0;
	ll P=1;
	int i;
	ll k=n-r;
	FOR(i,q) P*=p;
	ll mo=P;
	ll e0=0,eq1=0;
	if (fact[0]==0 || p!=pp || q!=pq) {
		pp=p; pq=q;
		fact[0]=1;
		for (int i=1;i<=P;++i) fact[i]=(i%p==0?fact[i-1]:fact[i-1]*i%mo);
	}
	ll a=1,b=1;
	if(p==2) {
		ll pm=P-1;
		for(ll v=n/P;v;v>>=1) eq1+=v;
		for(ll v=r/P;v;v>>=1) eq1-=v;
		for(ll v=k/P;v;v>>=1) eq1-=v;
		while(n) {
			a=a*fact[n&pm];
			b=((b*fact[r&pm])&pm)*fact[k&pm];
			a&=pm; b&=pm;
			n>>=1;
			r>>=1;
			k>>=1;
			e0+=n-r-k;
		}
	}
	else {
		for(ll v=n/P;v;v/=p) eq1+=v;
		for(ll v=r/P;v;v/=p) eq1-=v;
		for(ll v=k/P;v;v/=p) eq1-=v;
		while(n) {
			a=a*fact[n%P]%P;
			b=b*fact[r%P]%P*fact[k%P]%P;
			n/=p;
			r/=p;
			k/=p;
			e0+=n-r-k;
		}
	}
	
	
	ll s,t;
	ext_gcd(b,P,s,t);
	ll ret=a*((P+s)%mo)%mo;
  
	ret=ret*modpow(p,e0)%mo;
	if((p>2||q<=2)&&eq1&1) ret=(mo-ret)%mo;
	
	return ret;
}

ll ret[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R>>M;
	auto m=enumpr(M);
	
	R++;
	ll pmo=1;
	FORR2(a,b,m) {
		mo=1;
		FOR(i,b) mo*=a;
		//cout<<a<<" "<<mo<<endl;
		FOR(i,R-L) {
			ll v=lucas_ex(2*(L+i),L+i,a,b);
			auto p=crt(ret[i],pmo,v,mo);
			ret[i]=p.first;
		}
		pmo*=mo;
	}
	
	ll sum=0;
	FOR(i,R-L) sum+=ret[i]+M-2;
	cout<<sum%M<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
