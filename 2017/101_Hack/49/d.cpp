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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<int NV> class SegTree_Lazy {
public:
	vector<ll> val,mul;
	SegTree_Lazy(){val.resize(NV*2,1); mul.resize(NV*2,1);};
	ll comp(ll l,int r){ return l*r%mo;};

	ll getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 1;
		if(x<=l && r<=y) return mul[k];
		x=max(x,l);
		y=min(y,r);
		if(val[k]>=0) {
			return modpow(val[k],y-x);
		}
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int y,int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=v;
			mul[k]=modpow(v,r-l);
		}
		else if(l < y && x < r) {
			if(val[k]!=-1) {
				val[k*2]=val[k*2+1]=val[k];
				mul[k*2]=mul[k*2+1]=modpow(val[k],(r-l)/2);
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mul[k]=comp(mul[k*2],mul[k*2+1]);
		}
	}
};

int N,Q;
SegTree_Lazy<1<<20> st1,st2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		st1.update(i,i+1,x);
		st2.update(i,i+1,x-1);
	}
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			cin>>j;
			st1.update(x-1,y,j);
			st2.update(x-1,y,j-1);
		}
		else {
			ll a=st1.getval(x-1,y)-st2.getval(x-1,y);
			cout<<(a+mo)%mo<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
