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

ll mo;
int N,Q;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V r,V l){
		V m;
		m[0]=(l[0]*r[0]+l[1]*r[2])%mo;
		m[1]=(l[0]*r[1]+l[1]*r[3])%mo;
		m[2]=(l[2]*r[0]+l[3]*r[2])%mo;
		m[3]=(l[2]*r[1]+l[3]*r[3])%mo;
		return m;
	};
	
	SegTree_1(){val=vector<V>(NV*2,{1,0,0,1});};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {1,0,0,1};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<array<ll,4>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo>>Q;
	FOR(i,N) {
		array<ll,4> A;
		cin>>A[0]>>A[1]>>A[2]>>A[3];
		st.update(i,A);
	}
	while(Q--) {
		ll L,R,X,Y;
		cin>>L>>R>>X>>Y;
		auto A=st.getval(L,R);
		ll X2=(A[0]*X+A[1]*Y)%mo;
		ll Y2=(A[2]*X+A[3]*Y)%mo;
		cout<<(X2+mo)%mo<<" "<<(Y2+mo)%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
