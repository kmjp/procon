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


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int X) {
		int H=grid.size();
		int W=grid[0].size();
		ll sum=0;
		int x,y;
		vector<ll> V;
		FOR(y,H) FOR(x,W) {
			if((grid[y][x]-grid[0][0])%X) return -1;
			V.push_back((grid[y][x]-grid[0][0])/X);
		}
		ll cur=0;
		ll mi=1LL<<30;
		int pre=-10000;
        sort(ALL(V));
        FORR(v,V) cur+=abs(v-pre);
        mi=cur;
        int i;
        FOR(i,V.size()) {
			cur-=(V.size()-i)*(V[i]-pre);
			cur+=i*(V[i]-pre);
			mi=min(mi,cur);
			pre=V[i];
		}
        
        
        return mi;
    }
};
