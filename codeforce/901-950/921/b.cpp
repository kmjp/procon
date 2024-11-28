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


template<class V,int NV,ll mo> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	int rev2;
	SegTree_MulAdd(){
		rev2=(mo+1)/2;
		sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*mul[k]+add[k]*(y-x))%mo;
	}
	void propagate(int k,int s) {
		if(mul[k]==1&&add[k]==0) return;
		(mul[k*2]*=mul[k])%=mo;
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		(mul[k*2+1]*=mul[k])%=mo;
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		(add[k*2]+=add[k])%=mo;
		(sum[k*2]+=add[k]*s%mo*rev2)%=mo;
		(add[k*2+1]+=add[k])%=mo;
		(sum[k*2+1]+=add[k]*s%mo*rev2)%=mo;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(add[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])%mo;
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(add[k]+=v)%=mo;
			(sum[k]+=(r-l)*v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			(sum[k]=sum[k*2]+sum[k*2+1])%=mo;
		}
	}
};
SegTree_MulAdd<ll,1<<20,1000000007> st1;
SegTree_MulAdd<ll,1<<20,1000000009> st2;
const ll mo1=1000000007;
const ll mo2=1000000009;

ll modpow(ll a, ll n,ll mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
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
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	if(x<lcm) x+=lcm;
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

int N,M,Q;
int X[303030];
ll V[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	set<int> S;
	FOR(i,M) {
		cin>>X[i];
		X[i]--;
		S.insert(X[i]);
	}
	FOR(i,M) {
		cin>>x;
		V[X[i]]=x;
	}
	auto it=S.begin();
	FOR(i,N) {
		if(i>*it) it++;
		st1.doadd(i,i+1,(*it-i)*V[*prev(it)]%mo1);
		st2.doadd(i,i+1,(*it-i)*V[*prev(it)]%mo2);
	}
	
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			x--;
			V[x]=y;
			S.insert(x);
			it=S.find(x);
			ll a=modpow(V[*prev(it)],mo1-2,mo1)*y%mo1;
			ll b=modpow(V[*prev(it)],mo2-2,mo2)*y%mo2;
			st1.domul(x+1,*next(it),a);
			st2.domul(x+1,*next(it),b);
			st1.doadd(*prev(it)+1,x+1,mo1-V[*prev(it)]*(*next(it)-x)%mo1);
			st2.doadd(*prev(it)+1,x+1,mo2-V[*prev(it)]*(*next(it)-x)%mo2);
			
		}
		else {
			ll a=st1.getval(x-1,y);
			ll b=st2.getval(x-1,y);
			auto p=crt(a,mo1,b,mo2);
			cout<<p.first<<"\n";
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
