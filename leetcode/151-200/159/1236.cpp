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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> V;
        
        int i;
        FOR(i,startTime.size()) V.push_back({startTime[i],endTime[i],profit[i]});
        map<int,ll> M;
        ll ma=0;
        sort(ALL(V));
        FORR(e,V) {
			while(M.size() && M.begin()->first<=e[0]) {
				ma=max(ma,M.begin()->second);
				M.erase(M.begin());
			}
			M[e[1]]=max(M[e[1]],ma+e[2]);
		}
        FORR(m,M) ma=max(ma,m.second);
        return ma;
        
    }
};

