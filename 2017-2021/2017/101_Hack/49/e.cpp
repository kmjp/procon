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
ll K;

int A[202020],B[202020];

static const ll mo0=1000000007,mo1=1000000009;
static ll add0=1000010007, add1=1003333331;

ll rev(ll a, ll mo) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<int NV> class SegTree_Lazy {
public:
	vector<ll> val,mul;
	SegTree_Lazy(){val.resize(NV*2,0); mul.resize(NV*2,0);};
	ll comp(ll l,int r){ return l+r;};

	ll getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return mul[k];
		x=max(x,l);
		y=min(y,r);
		if(val[k]>=0) {
			return val[k]*(y-x);
		}
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int y,int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=v;
			mul[k]=v*(r-l);
		}
		else if(l < y && x < r) {
			if(val[k]!=-1) {
				val[k*2]=val[k*2+1]=val[k];
				mul[k*2]=mul[k*2+1]=val[k]*(r-l)/2;
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mul[k]=comp(mul[k*2],mul[k*2+1]);
		}
	}
};
SegTree_Lazy<1<<20> st;

static ll const def=1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,def); ma.resize(NV*2,def);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		if(val[k]>=0) return val[k];
		return min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=ma[k]=v;
		}
		else if(l < y && x < r) {
			if(val[k]>=0) {
				val[k*2]=val[k*2+1]=val[k];
				ma[k*2]=ma[k*2+1]=val[k];
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<20> st3;

ll hoge[404040][2];
set<pair<ll,ll>> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	add0=10009+(((ll)&add0)>>5)%259,add1=10007+(((ll)&add1)>>5)%257;
	
	cin>>N>>K;
	vector<int> MP;
	MP.push_back(-1);
	MP.push_back(1000000001);
	FOR(i,N) {
		cin>>A[i]>>B[i];
		MP.push_back(A[i]);
		MP.push_back(B[i]);
	}
	
	FOR(i,2*N+10) hoge[i][0]=hoge[i][1]=1;
	sort(ALL(MP));
	MP.erase(unique(ALL(MP)),MP.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(MP),A[i])-MP.begin();
		B[i]=lower_bound(ALL(MP),B[i])-MP.begin();
		hoge[A[i]][0] = hoge[A[i]][0]*(i+add0)%mo0;
		hoge[A[i]][1] = hoge[A[i]][1]*(i+add1)%mo1;
		hoge[B[i]][0] = hoge[B[i]][0]*rev(i+add0,mo0)%mo0;
		hoge[B[i]][1] = hoge[B[i]][1]*rev(i+add1,mo1)%mo1;
		st3.update(A[i],B[i],i+1);
	}
	
	S.insert({1,1});
	for(i=1;i<2*N+10;i++) {
		hoge[i][0]=hoge[i][0]*hoge[i-1][0]%mo0;
		hoge[i][1]=hoge[i][1]*hoge[i-1][1]%mo1;
		if(S.count({hoge[i][0],hoge[i][1]})==0) {
			st.update(i,i+1,1);
			S.insert({hoge[i][0],hoge[i][1]});
		}
	}
	K--;
	vector<int> V;
	FOR(i,N) {
		ll cnt=st.getval(A[i],B[i]);
		if(K<cnt) {
			V.push_back(i+1);
			st.update(0,A[i],0);
			st.update(B[i],2*N+10,0);
			st3.update(0,A[i],N+1);
			st3.update(B[i],2*N+10,N+1);
			if(st3.getval(A[i],B[i])==i+1) {
				if(K==0) break;
				else K--;
			}
		}
		else {
			K -= cnt;
			st.update(A[i],B[i],0);
			st3.update(A[i],B[i],N+1);
			
		}
	}
	
	_P("%d\n",V.size());
	FOR(i,V.size()) _P("%d%c",V[i],(i==V.size()-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
