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

int K,M,D,A,N;
ll T[202020],B[202020];
ll dp[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1LL<<60);
	V comp(V l,V r){ return max(l,r);};
	
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
SegTree_1<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>M>>D>>A>>N;
	FOR(i,N) {
		cin>>T[i+1]>>B[i+1];
		T[i+1]-=K;
	}
	T[N+1]=M-K;
	vector<int> X;
	X.push_back(-1);
	X.push_back(D);
	
	N+=2;
	FOR(i,N) X.push_back(T[i]%D);
	sort(ALL(X));
	X.erase(unique(ALL(X)),X.end());
	
	FOR(i,N) {
		x=lower_bound(ALL(X),T[i]%D)-X.begin();
		if(i) {
			dp[i]=max(st.getval(0,x)-(T[i]/D+1)*A,st.getval(x,X.size())-(T[i]/D)*A)+B[i];
		}
		st.update(x,dp[i]+T[i]/D*A);
	}
	cout<<dp[N-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
