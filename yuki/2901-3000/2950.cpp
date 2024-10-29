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
ll A[202020];
const ll mo=998244353;

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
SegTree_Mul<ll,1<<20> st;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

vector<pair<int,int>> MA,MI;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll ret=0;
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	
	MA={{1<<30,N}};
	MI={{0,N}};
	for(i=N-1;i>=0;i--) {
		st.domul(i,i+1,A[i]*A[i]%mo);
		while(MA.back().first<A[i]) {
			x=MA.back().first;
			y=MA.back().second;
			MA.pop_back();
			st.domul(y,MA.back().second,modpow(x)*A[i]%mo);
		}
		while(MI.back().first>A[i]) {
			x=MI.back().first;
			y=MI.back().second;
			MI.pop_back();
			st.domul(y,MI.back().second,modpow(x)*A[i]%mo);
		}
		MA.push_back({A[i],i});
		MI.push_back({A[i],i});
		
		(ret+=st.getval(i,N))%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
