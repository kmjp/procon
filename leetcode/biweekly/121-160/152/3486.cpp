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

int D[202020];
int LD[202020];
map<int,int> M;
vector<pair<int,int>> E[202020];
int V[202020];
int PC[202020];
set<pair<int,int>> S;
vector<int> DD;

int rl,rp;

class Solution {
public:
	void dfs(int cur,int pre,int d,int sd) {
		DD.push_back(cur);
		D[cur]=d;
		LD[cur]=sd;
		if(M.count(V[cur])==0) {
			PC[cur]=-1;
		}
		else {
			PC[cur]=M[V[cur]];
			S.insert({LD[DD[D[PC[cur]]+1]],D[PC[cur]]+1});
		}
		int crl,crp;
		if(S.size()<2) {
			crl=sd;
			crp=d+1;
		}
		else {
			auto it=S.rbegin();
			it++;
			int x=it->second;
			crl=sd-LD[DD[x]];
			crp=d-D[DD[x]]+1;
		}
		if(crl>rl || (crl==rl&&crp<rp)) rl=crl, rp=crp;
		
		
		M[V[cur]]=cur;
		FORR(e,E[cur]) if(e.first!=pre) {
			dfs(e.first,cur,d+1,sd+e.second);
		}
		if(PC[cur]==-1) {
			M.erase(V[cur]);
		}
		if(PC[cur]!=-1) {
			M[V[cur]]=PC[cur];
			S.erase({LD[DD[D[PC[cur]]+1]],D[PC[cur]]+1});
		}
		DD.pop_back();
	}
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int N=edges.size()+1;
        int i;
        FOR(i,N) {
			E[i].clear();
			V[i]=nums[i];
		}
		FORR(e,edges) {
			E[e[0]].push_back({e[1],e[2]});
			E[e[1]].push_back({e[0],e[2]});
		}
        M.clear();
        S.clear();
        rl=rp=0;
        dfs(0,0,0,0);
        return {rl,rp};
        
    }
};

