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
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,int>> V;
        int i;
        FOR(i,tasks.size()) {
			V.push_back({tasks[i][1]-tasks[i][0],i});
		}
		sort(ALL(V));
		ll cur=0;
		FORR(v,V) {
			ll a=tasks[v.second][0];
			ll m=tasks[v.second][1];
			cur=max(cur+a,m);
		}
		return cur;
    }
};
