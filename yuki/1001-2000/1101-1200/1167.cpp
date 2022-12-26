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
ll A[10101];

template<int NV> class SegTree_1 {
public:
	vector<vector<ll>> val;
	vector<ll> comp(vector<ll> V,vector<ll> W){
		if(V.size()<W.size()) swap(V,W);
		FORR(w,W) {
			FORR(v,V) w=min(w,v^w);
			if(w) V.push_back(w);
		}
		return V;
	}
	
	SegTree_1(){val.resize(NV*2);};
	vector<ll> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void build() {
		int i;
		for(i=NV-1;i>=1;i--) val[i]=comp(val[i*2],val[i*2+1]);
	}
};
SegTree_1<1<<15> st;
ll p2[10101];
int M,B[10101];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,10100) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]) st.val[(1<<15)+i].push_back(A[i]);
	}
	st.build();
	
	while(Q--) {
		cin>>M;
		FOR(i,M) cin>>B[i];
		B[M]=N;
		int num=0;
		int pre=0;
		FOR(i,M+1) {
			num+=(B[i]-pre)-st.getval(pre,B[i]).size();
			pre=B[i];
		}
		cout<<p2[num]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
