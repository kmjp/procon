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
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
		ll ret=0;
		while(startPos[0]<homePos[0]) {
			startPos[0]++;
			ret+=rowCosts[startPos[0]];
		}
		while(startPos[0]>homePos[0]) {
			startPos[0]--;
			ret+=rowCosts[startPos[0]];
		}
		while(startPos[1]<homePos[1]) {
			startPos[1]++;
			ret+=colCosts[startPos[1]];
		}
		while(startPos[1]>homePos[1]) {
			startPos[1]--;
			ret+=colCosts[startPos[1]];
		}
		
        return ret;
    }
};