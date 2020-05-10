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
vector<bool> H;
int ret;
class Solution {
public:
	
	int dfs(int cur,int pre) {
		int take=H[cur];
		FORR(e,E[cur]) if(e!=pre) take |= dfs(e,cur);
		if(take&&cur) ret+=2;
		return take;
	}

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        H=hasApple;
        int N=H.size();
        int i;
        FOR(i,N) E[i].clear();
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		
		ret=0;
		dfs(0,-1);
		return ret;
        
    }
};



