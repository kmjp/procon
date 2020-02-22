#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	BIT(){clear();};
	void clear() {ZERO(bit);};

	V total(int entry) {
		V s=0;
		entry++;
		while(entry>0) s+=bit[entry-1], entry -= entry & -entry;
		return s;
	}
	void update(int entry, V val) {
		entry++;
		while(entry <= (1<<ME)) bit[entry-1] += val, entry += entry & -entry;
	}
};

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return __gcd(abs(l),abs(r));};
	
	SegTree_1(){val.resize(NV*2); clear();};
	void clear() { int i; FOR(i,NV*2) val[i]=0;}
	
	V getval(int x,int y,int l,int r,int k) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	V getval(int x,int y) { return getval(x,y,0,NV,1);}
	void update(int entry, V v) {
		entry += NV;
		val[entry]+=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

BIT<int,19> bt;
SegTree_1<int,1<<19> st;


int N,M;
ll A[1000001];
ll D[1000001];


void solve() {
	int f,i,j,k,l,r,x,y,t;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	bt.update(1,A[0]);
	FOR(i,N-1) bt.update(i+2,A[i+1]-A[i]);
	FOR(i,N-1) st.update(i+2,A[i+1]-A[i]);
	
	cin>>M;
	FOR(i,M) {
		cin>>t>>x>>y;
		if(t!=0) {
			bt.update(x,t);
			bt.update(y+1,-t);
			st.update(x,t);
			st.update(y+1,-t);
		}
		else {
			_P("%d\n",__gcd(bt.total(y),st.getval(x+1,y+1)));
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


