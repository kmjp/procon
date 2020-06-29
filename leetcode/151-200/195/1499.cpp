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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ret=-1e9;
		deque<pair<int,int>> D;
        D.clear();
        
        int L,R=0;
        FOR(L,points.size()) {
			R=max(L,R);
			while(R<points.size() && points[L][0]+k>=points[R][0]) {
				int x=points[R][0]+points[R][1];
				while(D.size() && D.back().first<=x) D.pop_back();
				D.push_back({x,R});
				R++;
			}
			if(D.size() && D.front().second==L) D.pop_front();
			
			if(D.size()) ret=max(ret,points[L][1]-points[L][0]+D.front().first);
		}
		return ret;
        
    }
};
