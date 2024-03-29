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

int N,Q;
int L[202020],R[202020],B[202020];
vector<int> add[202020],del[202020];
int A[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>B[i];
		L[i]--;
		add[L[i]].push_back(B[i]);
		del[R[i]].push_back(B[i]);
	}
	multiset<int> E;
	E.insert(1);
	FOR(i,N) {
		FORR(a,add[i]) E.insert(a);
		FORR(a,del[i]) E.erase(E.find(a));
		A[i]=*E.rbegin();
		st.update(i,A[i]);
	}
	FOR(i,Q) {
		x=st.getval(L[i],R[i]);
		if(x!=B[i]) {
			cout<<-1<<endl;
			return;
		}
	}
	FOR(i,N) {
		cout<<A[i];
		if(i!=N-1) cout<<" ";
		else cout<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
