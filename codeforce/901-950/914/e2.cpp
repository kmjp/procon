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
vector<int> ev[202020];
vector<int> A[202020];
int ret[202020];

static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
	void update2(int entry,V v) {
		entry += NV;
		val[entry]=v;
		ma[entry]=v;
		while(entry>1) {
			entry>>=1;
			val[entry]=0;
			ma[entry]=max(ma[entry*2],ma[entry*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;
vector<int> E[202020];
int id;
int L[202020],R[202020],D[202020];
vector<int> Ls[202020];

void dfs(int cur,int pre) {
	if(cur) D[cur]=D[pre]+1;
	L[cur]=id++;
	st.update2(L[cur],D[cur]);
	vector<int> es;
	FORR(e,E[cur]) if(e!=pre) es.push_back(e);
	E[cur]=es;
	FORR(e,E[cur]) {
		dfs(e,cur);
		Ls[cur].push_back(R[e]);
	}
	R[cur]=id;
	
}
void dfs2(int cur) {
	
	FORR(i,ev[cur]) {
		FORR(a,A[i]) {
			if(L[cur]>L[a]&&L[cur]<R[a]) {
				st.update(0,N,-1<<20);
				int x=lower_bound(ALL(Ls[a]),L[cur]+1)-Ls[a].begin();
				int c=E[a][x];
				st.update(L[c],R[c],1<<20);
			}
			else {
				st.update(L[a],R[a],-1<<20);
			}
		}
		/*
		cout<<cur<<" "<<i<<" # ";
		int j;
		FOR(j,N) cout<<st.getval(L[j],L[j]+1)<<", ";
		cout<<endl;
		*/
		ret[i]=st.getval(0,N);
		FORR(a,A[i]) {
			if(L[cur]>L[a]&&L[cur]<R[a]) {
				st.update(0,N,1<<20);
				int x=lower_bound(ALL(Ls[a]),L[cur]+1)-Ls[a].begin();
				int c=E[a][x];
				st.update(L[c],R[c],-1<<20);
			}
			else {
				st.update(L[a],R[a],1<<20);
			}
		}
	}
	
	/*
	cout<<cur<<" ";
	int i;
	FOR(i,N) cout<<st.getval(L[i],L[i]+1);
	cout<<endl;
	*/
	FORR(e,E[cur]) {
		st.update(0,N,1);
		st.update(L[e],R[e],-2);
		dfs2(e);
		st.update(L[e],R[e],2);
		st.update(0,N,-1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,Q) {
		cin>>x>>y;
		ev[x-1].push_back(i);
		FOR(j,y) {
			cin>>x;
			A[i].push_back(x-1);
		}
	}
	dfs(0,0);
	dfs2(0);
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
