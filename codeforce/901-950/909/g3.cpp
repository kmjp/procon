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

int T,N,Q;
vector<int> E[202020];
int P[202020];
int VL[202020],VR[202020],id;
int L[202020],R[202020],X[202020],ret[202020];
vector<pair<int,int>> ev[202020];
const int DI=320;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt;

void dfs(int cur,int pre) {
	VL[cur]=id++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	VR[cur]=id;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) E[i].clear();
		
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
		}
		FOR(i,DI) ev[i].clear();
		FOR(i,Q) {
			cin>>L[i]>>R[i]>>X[i];
			L[i]--;
			X[i]--;
			ev[L[i]/DI].push_back({R[i],i});
		}
		
		id=0;
		dfs(0,0);

		int CL=0,CR=0;
		FOR(i,DI) {
			sort(ALL(ev[i]));
			FORR2(r,ci,ev[i]) {
				while(CR<r) bt.add(VL[P[CR++]],1);
				while(CR>r) bt.add(VL[P[--CR]],-1);
				while(CL<L[ci]) bt.add(VL[P[CL++]],-1);
				while(CL>L[ci]) bt.add(VL[P[--CL]],1);
				ret[ci]=bt(VR[X[ci]]-1)-bt(VL[X[ci]]-1);
			}
		}
		while(CL<CR) bt.add(VL[P[CL++]],-1);
		
		FOR(i,Q) {
			
			if(ret[i]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
			
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
