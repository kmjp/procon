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

int E[101][101];


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        ZERO(E);
        int i,x,y;
        FORR(r,roads) E[r[0]][r[1]]=E[r[1]][r[0]]=1;
        int ma=0;
        FOR(y,n) FOR(x,y) {
			int cur=0;
			FOR(i,n) if(E[x][i]) cur++;
			FOR(i,n) if(E[y][i]) cur++;
			if(E[x][y]) cur--;
			ma=max(ma,cur);
		}
		return ma;
    }
};
