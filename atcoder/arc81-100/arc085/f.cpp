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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
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
SegTree_1<int,1<<20> st;

int N;
int S[202020];
int Q;
vector<int> ev[202020];
int dp[202020];


void solve() {
	int i,j,k,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		dp[0]+=x;
		if(x==1) S[i+1]=S[i]-1;
		else S[i+1]=S[i]+1;
	}
	
	
	FOR(i,N+1) {
		if(i) dp[i]=1<<20;
		st.update(i,dp[i]+(S[N]-S[i]));
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		ev[x].push_back(y);
	}
	for(i=1;i<=N;i++) {
		FORR(r,ev[i]) {
			x = min(dp[i-1]+(S[r]-S[i-1]),st.getval(i,r+1) - (S[N]-S[r]));
			if(x<dp[r]) {
				dp[r]=x;
				st.update(r,dp[r]+(S[N]-S[r]));
			}
		}
		dp[i]=min(dp[i],dp[i-1]);
		
	}
	cout<<*min_element(dp,dp+N+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
