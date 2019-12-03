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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> R;
        FORR(v,intervals) {
			if(v[1]<=toBeRemoved[0] || toBeRemoved[1]<=v[0]) {
				R.push_back(v);
			}
			else {
				if(v[0]<toBeRemoved[0]) {
					R.push_back({v[0],toBeRemoved[0]});
				}
				if(toBeRemoved[1]<v[1]) {
					R.push_back({toBeRemoved[1],v[1]});
				}
			}
			
		}
		sort(ALL(R));
		return R;
    }
};

