
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

class SCC_BI {
public:
	static const int MV = 210000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { assert(NV); E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

class Solution {
public:
  
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        SCC_BI scc;
        scc.init(n);
        FORR(v,connections) scc.add_edge(v[0],v[1]);
        scc.scc();
        vector<vector<int>> T;
        FORR(v,scc.BR) T.push_back({v.first,v.second});
        return T;
        
    }
};