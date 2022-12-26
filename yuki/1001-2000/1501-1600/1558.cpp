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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V def;
	// static V const def=1LL<<60; min
	V comp(V l,V r){
		vector<int> S(18);
		int i;
		FOR(i,18) S[i]=r[l[i]];
		return S;
	};
	
	SegTree_1(){
		def.resize(18);
		int i;
		FOR(i,18) def[i]=i;
		val.resize(NV*2);
		FOR(i,NV*2) val[i]=def;
	};
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

SegTree_1<vector<int>,1<<16> st;
int N,M,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			vector<int> V(18);
			FOR(i,18) V[i]=i;
			FOR(i,N) {
				cin>>V[i];
				V[i]--;
			}
			st.update(x,V);
		}
		else if(i==2) {
			cin>>x;
			auto a=st.getval(1,x+1);
			vector<int> R(N);
			FOR(i,N) R[a[i]]=i+1;
			FORR(r,R) cout<<r<<" ";
			cout<<endl;
		}
		else {
			cin>>x>>y;
			auto a=st.getval(x,y+1);
			int ret=0;
			FOR(i,N) ret+=abs(i-a[i]);
			cout<<ret<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
