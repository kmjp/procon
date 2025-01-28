#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

class SCC {
public:
	static const int MV = 26;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};


class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
		SCC scc;
		int tmask=0;
		FORR(a,words) {
			tmask|=1<<(a[0]-'a');
			tmask|=1<<(a[1]-'a');
		}
		
		vector<pair<int,string>> V;
		int mi=101010;
		int mask;
		for(int mask=tmask;mask>=0;mask--) {
			mask=mask&tmask;
			if(__builtin_popcount(mask)+__builtin_popcount(tmask)>mi) continue;
			vector<string> L;
			int ng=0;
			
			scc.init(26);
			FORR(w,words) {
				if(mask&(1<<(w[0]-'a'))) continue;
				if(mask&(1<<(w[1]-'a'))) continue;
				if(w[0]==w[1]) ng++;
				scc.add_edge(w[0]-'a',w[1]-'a');
			}
			if(ng) continue;
			scc.scc();
			if(scc.SC.size()!=26) continue;
			string T;
			int i;
			FOR(i,26) {
				if(tmask&(1<<i)) T+='a'+i;
				if(mask&(1<<i)) T+='a'+i;
			}
			V.push_back({T.size(),T});
			mi=min(mi,(int)T.size());
		}
		sort(ALL(V));
		vector<vector<int>> ret;
		FORR(a,V) if(a.first==V[0].first) {
			vector<int> b(26);
			FORR(c,a.second) b[c-'a']++;
			ret.push_back(b);
		}
		return ret;
        
    }
};


