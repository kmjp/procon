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

int N,K,V;
string S[101010];
map<string,int> M;
string T[202020];
int A[101010],B[101010];

template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	vector<int> E[MV];
	void add_path(int x,int y) { E[x].push_back(y);}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int e=E[cur].back();
			E[cur].pop_back();
			dfs(e);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		assert(NV);
		int te=0,i;
		vector<int> deg(NV);
		FOR(i,NV) {
			te += E[i].size();
			deg[i]+=E[i].size();
			FORR(e,E[i]) deg[e]--;
		}
		int d0=0,s=0;
		FOR(i,NV) {
			if(deg[i]>1 || deg[i]<-1) return false;
			if(deg[i]==0) d0++;
			if(deg[i]==1) s=i;
		}
		if(d0!=NV && d0+2!=NV) return false;
		dfs(s);
		reverse(path.begin(),path.end());
		return path.size()==te+1;
	}
};

DirectedEulerPath<202020> dep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>S[i];
	
	if(K==1) {
		FOR(i,N) cout<<S[i];
		cout<<endl;
		return;
	}
	
	FOR(i,N) M[S[i].substr(0,K-1)]=M[S[i].substr(1,K-1)]=0;
	x=0;
	FORR(r,M) T[x]=r.first, r.second=x++;
	
	V=M.size();
	dep.init(V);
	FOR(i,N) {
		A[i]=M[S[i].substr(0,K-1)];
		B[i]=M[S[i].substr(1,K-1)];
		dep.add_path(A[i],B[i]);
	}
	if(!dep.GetPath()) return _P("-1\n");
	
	string ret=T[dep.path[0]];
	for(i=1;i<dep.path.size();i++) ret+=T[dep.path[i]].back();
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
