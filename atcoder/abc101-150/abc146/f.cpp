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

int N,M;
string S;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=1<<30;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<20> st;

int dp[202020];
int from[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	
	dp[N]=0;
	st.update(N,0);
	for(i=N-1;i>=0;i--) if(S[i]=='0') {
		auto p=st.getval(i+1,min(i+M+1,N+1));
		from[i]=p.second;
		dp[i]=p.first+1;
		st.update(i,dp[i]);
	}
	
	if(dp[0]>=1<<30) {
		cout<<-1<<endl;
	}
	else {
		int cur=0;
		while(cur<N) {
			cout<<from[cur]-cur<<" ";
			cur=from[cur];
		}
		cout<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
