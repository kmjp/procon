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
int A[303030];
const ll mo=998244353;

int rev2=(mo+1)/2;
template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*mul[k]+add[k]*(y-x))%mo;
	}
	void propagate(int k,int s) {
		(mul[k*2]*=mul[k])%=mo;
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		(add[k*2]+=add[k])%=mo;
		(sum[k*2]+=add[k]*s%mo*rev2)%=mo;
		(mul[k*2+1]*=mul[k])%=mo;
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

SegTree_MulAdd<ll,1<<20> stma,stmi;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> ma,mi;
	ma.push_back({1<<30,0});
	mi.push_back({-1,0});
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		cin>>x;
		
		if(i==1) {
			ret=1;
		}
		else {
			ret=(stma.sum[1]-stmi.sum[1]+mo)%mo;
		}
		//�V�K
		stma.doadd(i,i+1,ret*x%mo);
		stmi.doadd(i,i+1,ret*x%mo);
		//�L�΂�
		ma.push_back({x,i});
		while(ma[ma.size()-2].first<ma.back().first) {
			int id=ma[ma.size()-2].second;
			int v=ma[ma.size()-2].first;
			stma.domul(id,ma.back().second,modpow(v)*x%mo);
			ma.pop_back();
			ma.back().first=x;
		}
		mi.push_back({x,i});
		while(mi[mi.size()-2].first>mi.back().first) {
			int id=mi[mi.size()-2].second;
			int v=mi[mi.size()-2].first;
			stmi.domul(id,mi.back().second,modpow(v)*x%mo);
			mi.pop_back();
			mi.back().first=x;
		}
		
	}
	ret=(stma.sum[1]-stmi.sum[1]+mo)%mo;
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
