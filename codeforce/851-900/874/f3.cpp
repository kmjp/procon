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

int T,N,M,A[202020];
const ll mo=1000000007;
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){ return l*r%mo;};
	
	SegTree_1(){val=vector<V>(NV*2,1);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 1;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>A[i];
		vector<int> V={1};
		sort(A,A+N);
		
		for(i=1;i<N;i++) {
			if(A[i]==A[i-1]) {
				V.back()++;
			}
			else if(A[i]==A[i-1]+1) {
				V.push_back(1);
			}
			else {
				V.push_back(0);
				V.push_back(1);
			}
		}
		FOR(i,V.size()) {
			st.update(i,V[i]);
		}
		ll ret=0;
		FOR(i,V.size()) if(i+M<=V.size()) {
			ret+=st.getval(i,i+M);
		}
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
