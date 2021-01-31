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
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> M;
        FORR(e,adjacentPairs) {
			M[e[0]].push_back(e[1]);
			M[e[1]].push_back(e[0]);
		}
		int start=0;
		vector<int> R;
		FORR(m,M) if(m.second.size()==1) start=m.first;
		int pre=-1000000;
		while(1) {
			R.push_back(start);
			int nex=-1000000;
			FORR(a,M[start]) {
				if(a!=pre) nex=a;
			}
			if(nex==-1000000) break;
			pre=start;
			start=nex;
			
		}
		return R;
		
		
    }
};
