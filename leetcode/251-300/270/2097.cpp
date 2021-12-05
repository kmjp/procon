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
unordered_map<int,int> M;
vector<int> R;
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        M.clear();
        R.clear();
        int i;
        FORR(p,pairs) {
			FOR(i,2) {
				if(M.count(p[i])==0) {
					int x=M.size();
					R.push_back(p[i]);
					M[p[i]]=x;
				}
				p[i]=M[p[i]];
				
			}
		}
		dep.init(M.size());
		FORR(p,pairs) {
			dep.add_path(p[0],p[1]);
		}
		dep.GetPath();
		vector<vector<int>> ret;
		int a;
		FOR(a,dep.path.size()-1) {
			ret.push_back({R[dep.path[a]],R[dep.path[a+1]]});
		}
		return ret;
    }
};
