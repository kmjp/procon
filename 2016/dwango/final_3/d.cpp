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

int N,Q;
int L[202020],R[202020],X[202020],Y[202020];
ll V[202020];


template<class V,int NV> class SegTree_2 {
public:
	vector<V> mi,add;
	SegTree_2(){mi.resize(NV*2,1LL<<58); add.resize(NV*2);};
	V getval(int k) {
		int e = k+NV;
		return mi[e]+add[e];
	}
	void prop(int k) {
		mi[2*k]=min(mi[2*k],mi[k]-add[2*k]);
		add[2*k]+=add[k];
		mi[2*k+1]=min(mi[2*k+1],mi[k]-add[2*k+1]);
		add[2*k+1]+=add[k];
		mi[k]=1LL<<58;
		add[k]=0;
	}
	
	void prop() {
		for(int k=1;k<NV;k++) prop(k);
	}
	
	void update(int x,int y, V A, V M,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mi[k]=min(mi[k],M-add[k]);
			add[k]+=A;
		}
		else if(l < y && x < r) {
			prop(k);
			update(x,y,A,M,l,(l+r)/2,k*2);
			update(x,y,A,M,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<ll,1<<20> st2;

template<class V,int NV> class RMQ_range {
public:
	vector<V> val, ma;
	RMQ_range(){ val.resize(NV*2,0); ma.resize(NV*2,0); };
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return -1LL<<60;
		if(x<=l && r<=y) return ma[k];
		return max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)) + val[k];
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]) + val[k];
		}
	}
};
RMQ_range<ll,1<<20> rmq;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>X[i]>>Y[i];
		L[i]--;
	}
	for(i=Q-1;i>=0;i--) st2.update(L[i],R[i],-X[i],Y[i]);
	
	st2.prop();
	
	FOR(i,N) {
		V[i]=st2.getval(i);
		rmq.update(i,i+1,V[i]);
	}
	FOR(i,Q) {
		rmq.update(L[i],R[i],X[i]);
		if(rmq.getval(L[i],R[i])!=Y[i]) return _P("NG\n");
	}
	
	_P("OK\n");
	FOR(i,N) _P("%lld ",V[i]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
