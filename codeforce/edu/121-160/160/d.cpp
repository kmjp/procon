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

int T,N;
int P[303030];
ll TL[303030],TR[303030];
const ll mo=998244353;

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
map<pair<int,int>,ll> memo;

ll dfs(int L,int R) {
	//1å¬à»è„écÇ∑
	if(R<L) return 0;
	if(memo.count({L,R})) return memo[{L,R}];
	pair<int,int> p=st.getval(L,R+1);
	int M=p.second;
	
	ll ret=0;
	if(L==0) {
		//MÇè¡Ç∑
		ret+=dfs(L,M-1);
	}
	else if(R==N-1) {
		//MÇè¡Ç∑
		ret+=dfs(M+1,R);
	}
	else {
		//ç∂ÇécÇ∑
		ret+=dfs(L,M-1)+dfs(M+1,R);
	}
	//MÇécÇ∑
	ret+=(1+dfs(L,M-1))*(1+dfs(M+1,R));
	
	return memo[{L,R}]=ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			st.update(i,P[i]);
		}
		memo.clear();
		
		pair<int,int> p=st.getval(0,N);
		ll ret=(1+dfs(0,p.second-1))*(1+dfs(p.second+1,N-1))%mo;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
