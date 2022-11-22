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
int C[101010];
int S;
ll ret;
class Solution {
public:
	int dfs(int cur,int pre) {
		C[cur]=1;
		FORR(e,E[cur]) if(e!=pre) {
			int a=dfs(e,cur);
			ret+=(a+S-1)/S;
			C[cur]+=a;
			
		}
		return C[cur];
	}
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        S=seats;
        ret=0;
        int i,N=roads.size()+1;
        FOR(i,N) E[i].clear();
        FORR(a,roads) E[a[0]].push_back(a[1]),E[a[1]].push_back(a[0]);
        dfs(0,0);
        return ret;
    }
};
