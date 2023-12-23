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

int N,K;
ll SX,SY;
ll X[202020],Y[202020];

double const def=1e18;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<double,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>SX>>SY;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]-=SX;
		Y[i]-=SY;
	}
	double base=hypot(X[0],Y[0])+hypot(X[N-1],Y[N-1]);
	FOR(i,N-1) base+=hypot(X[i]-X[i+1],Y[i]-Y[i+1]);
	
	st.update(0,0);
	
	for(i=1;i<N;i++) {
		double a=hypot(X[i],Y[i])+hypot(X[i-1],Y[i-1])-hypot(X[i-1]-X[i],Y[i-1]-Y[i])+st.getval(max(i-K,0),i);
		st.update(i,a);
	}
	base+=st.getval(N-K,N);
	_P("%.12lf\n",base);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
