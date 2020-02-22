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

static ll const def=1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=0;
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};

int N,Q,A,B;
SegTree_3<ll,1<<20> stl,str;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>A>>B;
	for(i=1;i<=N;i++) {
		if(i!=B) {
			stl.update(i,i+1,(1LL<<50)+i);
			str.update(i,i+1,(1LL<<50)-i);
		}
		else {
			stl.update(i,i+1,i);
			str.update(i,i+1,-i);
		}
	}
	ll pre=A;
	while(Q--) {
		ll X;
		cin>>X;
		
		// move other
		ll mi=min(stl.getval(X,N+1)-X,str.getval(1,X+1)+X);
		// move pre
		stl.update(1,N+1,abs(X-pre));
		str.update(1,N+1,abs(X-pre));
		
		// move other
		ll x=stl.getval(pre,pre+1)-pre;
		if(mi<x) stl.update(pre,pre+1,mi-x);
		x=str.getval(pre,pre+1)+pre;
		if(mi<x) str.update(pre,pre+1,mi-x);
		
		pre=X;
	}
	
	ll ret=1LL<<60;
	for(i=1;i<=N;i++) ret=min(ret,stl.getval(i,i+1)-i);
	for(i=1;i<=N;i++) ret=min(ret,str.getval(i,i+1)+i);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
