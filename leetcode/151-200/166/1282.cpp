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
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		map<int,vector<int>> M;
		int i;
		FOR(i,groupSizes.size()) {
			M[groupSizes[i]].push_back(i);
		}
		vector<vector<int>> V;
		FORR(m,M) {
			int j;
			vector<int> R;
			FORR(c,m.second) {
				R.push_back(c);
				if(R.size()==m.first) {
					V.push_back(R);
					R.clear();
				}
			}
		}
		return V;
    }
};


