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

map<vector<int>,int> memo;


class Solution {
public:
	int dfs(int b,vector<int> G) {
		int sum=0;
		int i;
		if(memo.count(G)) return memo[G];
		FOR(i,b) sum+=i*G[i];
		if(sum==0) return 0;
		int rem=sum%b;
		int ret=0;
		FOR(i,b) if(G[i]) {
			G[i]--;
			ret=max(ret,dfs(b,G)+(rem==i));
			G[i]++;
		}
		return memo[G]=ret;
	}

    int maxHappyGroups(int batchSize, vector<int>& groups) {
		vector<int> G(batchSize);
		int num=0;
		FORR(g,groups) G[g%batchSize]++;
		int ret=G[0];
		G[0]=0;
		memo.clear();
		return ret+dfs(batchSize,G);
		
    }
};
