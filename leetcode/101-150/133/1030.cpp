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

    int twoCitySchedCost(vector<vector<int>>& costs) {
		vector<int> V;
		int sum=0;
		
		FORR(c,costs) {
			sum+=c[1];
			V.push_back(c[0]-c[1]);
		}
		sort(ALL(V));
		int i;
		FOR(i,costs.size()/2) sum+=V[i];
		return sum;
        
    }

};

