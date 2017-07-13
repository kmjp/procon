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

ll mo=1000000007;

template<class V,int NV> class SegTree {
public:
	vector<V> mult,sum;
	SegTree(){mult.resize(NV*2,1); sum.resize(NV*2,0);}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mult[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(mult[2*k]*sum[2*k]+mult[2*k+1]*sum[2*k+1])%mo;
		}
	}
	void add(int x,int v) {
		x+=NV;
		while(x>0) {
			(sum[x]+=v)%=mo;
			x/=2;
		}
	}
	
};

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int N;
ll A[101010];
SegTree<ll,1<<20> st;
ll p2[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> miv,mav;
	miv.push_back({0,-1});
	mav.push_back({101010101,-1});
	
	p2[0]=1;
	FOR(i,101000) p2[i+1]=p2[i]*2%mo;
	
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		st.add(i,(i)?p2[i-1]:1);
		st.update(i,i+1,A[i]*A[i]%mo);
		while(mav.size()>=2 && mav.back().first<=A[i]) {
			ll mul=A[i]*modpow(mav.back().first)%mo;
			x=mav.back().second;
			mav.pop_back();
			y=mav.back().second;
			st.update(y+1,x+1,mul);
		}
		mav.push_back({A[i],i});
		while(miv.size()>=2 && miv.back().first>=A[i]) {
			ll mul=A[i]*modpow(miv.back().first)%mo;
			x=miv.back().second;
			miv.pop_back();
			y=miv.back().second;
			st.update(y+1,x+1,mul);
		}
		miv.push_back({A[i],i});
		ll val = st.mult[1]*st.sum[1]%mo;
		
		(ret += val*(N-i-2>=0?p2[N-i-2]:1))%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
