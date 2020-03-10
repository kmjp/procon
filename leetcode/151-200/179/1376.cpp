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



vector<int> E[101010];
int ma;
vector<int> T;
class Solution {
public:
	void dfs(int cur,int now) {
		ma=max(ma,now);
		now+=T[cur];
		FORR(e,E[cur]) dfs(e,now);
	}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		T=informTime;
        int i;
        FOR(i,n) E[i].clear();
        FOR(i,n) if(i!=headID) E[manager[i]].push_back(i);
        ma=0;
        dfs(headID,0);
        return ma;
    }
};

