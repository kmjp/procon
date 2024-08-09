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
vector<int> C[303030];
int A[303030];
int L[303030],R[303030],id;

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
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
};
SegTree_3<int,1<<20> st;

void dfs(int cur) {
	L[cur]=id++;
	FORR(e,C[cur]) dfs(e);
	R[cur]=id;
}
set<pair<int,int>> S[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			C[i].clear();
			S[i].clear();
		}
		for(i=1;i<N;i++) {
			cin>>P[i];
			P[i]--;
			C[P[i]].push_back(i);
		}
		id=0;
		dfs(0);
		
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
		}
		ll ret=0;
		for(i=N-1;i>=0;i--) {
			vector<ll> V={1,1};
			FORR(c,C[i]) {
				auto it=S[c].lower_bound({A[i],0});
				while(it!=S[c].end()&&it->first==A[i]) {
					x=it->second;
					st.update(L[x],R[x],-1);
					it=S[c].erase(it);
				}
				V.push_back(1+st.getval(L[c],R[c]));
				if(S[i].size()<S[c].size()) swap(S[i],S[c]);
				FORR(a,S[c]) S[i].insert(a);
				S[c].clear();
			}
			st.update(L[i],R[i],1);
			sort(ALL(V));
			reverse(ALL(V));
			ret=max(ret,V[0]*V[1]);
			S[i].insert({A[i],i});
		}
		cout<<ret<<endl;
		FORR2(a,b,S[0]) {
			st.update(L[b],R[b],-1);
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
