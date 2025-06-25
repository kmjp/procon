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

int N;
int Y[202020],R[202020];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int rev2=(mo+1)/2;
template<class V,int NV> class SegTree_Mul {
public:
	vector<V> sum,mul; // sum stores val after muladd
	SegTree_Mul(){
		sum.resize(NV*2,1); mul.resize(NV*2,1);
		for(int i=NV-1;i>=1;i--) sum[i]=sum[i*2]+sum[i*2+1];
	};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*mul[k])%mo;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])*mul[k]%mo;
		}
	}
};
SegTree_Mul<ll,1<<18> Ln,Rn,Ls,Rs,num;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>Y[i];
		Y[i]--;
		R[Y[i]]=i;
	}
	FOR(i,N) {
		Rs.sum[(1<<18)+i]=i*modpow(2,N-1-i)%mo;
		Ls.sum[(1<<18)+i]=i*modpow(2,i)%mo;
		Rn.sum[(1<<18)+i]=modpow(2,N-1-i)%mo;
		Ln.sum[(1<<18)+i]=modpow(2,i)%mo;
	}
	FOR(i,1<<19) {
		Rs.mul[i]=1;
		Ls.mul[i]=1;
		Rn.mul[i]=1;
		Ln.mul[i]=1;
	}
	for(i=(1<<18)-1;i>=0;i--) {
		Rs.sum[i]=(Rs.sum[i*2]+Rs.sum[i*2+1])%mo;
		Ls.sum[i]=(Ls.sum[i*2]+Ls.sum[i*2+1])%mo;
		Rn.sum[i]=(Rn.sum[i*2]+Rn.sum[i*2+1])%mo;
		Ln.sum[i]=(Ln.sum[i*2]+Ln.sum[i*2+1])%mo;
	}
	
	
	ll ret=0;
	FOR(i,N) {
		x=R[N-1-i];
		//âEë§
		ll RR=(Ls.getval(x+1,N)-x*Ln.getval(x+1,N))%mo*modpow(2)%mo;
		//ç∂ë§
		ll LL=((x*Rn.getval(0,x)-Rs.getval(0,x))%mo*modpow(2)%mo);
		(ret+=(N-1-i)*(LL+RR))%=mo;
		Rs.domul(0,x,modpow(2));
		Rn.domul(0,x,modpow(2));
		Ls.domul(x,N,modpow(2));
		Ln.domul(x,N,modpow(2));
		Rs.domul(x,x+1,0);
		Ls.domul(x,x+1,0);
		Rn.domul(x,x+1,0);
		Ln.domul(x,x+1,0);
	}
	
	FOR(i,N) {
		Rs.sum[(1<<18)+i]=i*modpow(2,N-1-i)%mo;
		Ls.sum[(1<<18)+i]=i*modpow(2,i)%mo;
		Rn.sum[(1<<18)+i]=modpow(2,N-1-i)%mo;
		Ln.sum[(1<<18)+i]=modpow(2,i)%mo;
	}
	FOR(i,1<<19) {
		Rs.mul[i]=1;
		Ls.mul[i]=1;
		Rn.mul[i]=1;
		Ln.mul[i]=1;
	}
	for(i=(1<<18)-1;i>=0;i--) {
		Rs.sum[i]=(Rs.sum[i*2]+Rs.sum[i*2+1])%mo;
		Ls.sum[i]=(Ls.sum[i*2]+Ls.sum[i*2+1])%mo;
		Rn.sum[i]=(Rn.sum[i*2]+Rn.sum[i*2+1])%mo;
		Ln.sum[i]=(Ln.sum[i*2]+Ln.sum[i*2+1])%mo;
	}
	FOR(i,N) {
		x=R[i];
		//âEë§
		ll RR=(Ls.getval(x+1,N)-x*Ln.getval(x+1,N))%mo*modpow(2)%mo;
		//ç∂ë§
		ll LL=((x*Rn.getval(0,x)-Rs.getval(0,x))%mo*modpow(2)%mo);
		(ret-=i*(LL+RR))%=mo;
		Rs.domul(0,x,modpow(2));
		Rn.domul(0,x,modpow(2));
		Ls.domul(x,N,modpow(2));
		Ln.domul(x,N,modpow(2));
		Rs.domul(x,x+1,0);
		Ls.domul(x,x+1,0);
		Rn.domul(x,x+1,0);
		Ln.domul(x,x+1,0);
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
