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


ll sum,cs;
vector<int> E[101010];
int G[101010];
int NG[20];
class Solution {
public:
	int dfs(int cur,int pre,int col) {
		int c=(col==G[cur]);
		FORR(e,E[cur]) if(e!=pre) c+=dfs(e,cur,col);
		sum+=1LL*c*(NG[col]-c);
		return c;
		
		
	}
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        sum=0;
        int i;
        ZERO(NG);
        FOR(i,n) {
			G[i]=group[i]-1;
			E[i].clear();
			NG[G[i]]++;
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		sum=0;
		FOR(i,20) dfs(0,0,i);
		return sum;
        
    }
};
