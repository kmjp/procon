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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int N=capacity.size();
        vector<int> V;
        int i;
        FOR(i,N) V.push_back(capacity[i]-rocks[i]);
        sort(ALL(V));
        int ok=0;
        FORR(a,V) {
			int v=min(a,additionalRocks);
			if(v==a) {
				ok++;
			}
			additionalRocks-=v;
		}
		return ok;
    }
};
