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

int N;
vector<pair<int,int>> E[202020];
pair<int,int> P[202020];

int id,L[202020],R[202020],re[202020];
ll D[202020];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<pair<V,int>> ma;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) ma[i+NV]={0,-i};
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {-1LL<<60,0};
		if(x<=l && r<=y) return ma[k];
		auto p=max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));;
		p.first+=val[k];
		return p;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first+=val[k];
		}
	}
};
SegTree_3<ll,1<<20> st;


void dfs(int cur,int pre) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR2(e,c,E[cur]) if(e==pre) {
		P[cur]={e,c};
		D[cur]=D[e]+c;
	}
	FORR2(e,c,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	
	dfs(0,0);
	FOR(i,N) {
		st.update(L[i],L[i]+1,D[i]);
	}
	ll sum=0;
	FOR(i,N) {
		auto p=st.getval(0,N);
		sum+=p.first*2;
		int cur=re[-p.second];
		st.update(L[cur],L[cur]+1,-1);
		while(P[cur].second) {
			st.update(L[cur],R[cur],-P[cur].second);
			P[cur].second=0;
			cur=P[cur].first;
			
		}
		
		cout<<sum<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
