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

vector<int> E[101010];
ll D[202020][3];

class Solution {
public:
	void dfs(int cur,int pre,int d,int id) {
		D[cur][id]=d;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1,id);
	}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int i;
        FOR(i,n) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		dfs(x,x,0,0);
		dfs(y,y,0,1);
		dfs(z,z,0,2);
		int ret=0;
		FOR(i,n) {
			int add=0;
			if(D[i][0]*D[i][0]+D[i][1]*D[i][1]==D[i][2]*D[i][2]) add=1;
			if(D[i][0]*D[i][0]+D[i][2]*D[i][2]==D[i][1]*D[i][1]) add=1;
			if(D[i][2]*D[i][2]+D[i][1]*D[i][1]==D[i][0]*D[i][0]) add=1;
			ret+=add;
		}
		return ret;
    }
};


 