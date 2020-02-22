#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,L;
int LL[100005],RR[100005],C[100005];
vector<int> P[100001];
set<int> S;
ll cost[100002];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val.resize(NV*2); clear();};
	void clear() { int i; FOR(i,NV*2) val[i]=def;}
	
	V getval(int x,int y,int l,int r,int k) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	V getval(int x,int y) { return getval(x,y,0,NV,1);}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>L;
	FOR(i,N) cin>>LL[i]>>RR[i]>>C[i];
	FOR(i,N) P[RR[i]].push_back(i);
	
	SegTree_1<ll,1<<20> st;
	
	FOR(i,L+5) st.update(i,1LL<<60);
	st.update(0,0);
	
	FOR(i,L+1) {
		ll re=1LL<<60;
		ITR(it,P[i]) {
			x=*it;
			re=min(re,min(st.getval(i,i),st.getval(LL[x],i)+C[x]));
		}
		if(re<1LL<<60) st.update(i,re);
	}
	cout << st.getval(L,L+1) << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


