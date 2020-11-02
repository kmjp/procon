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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		int N=heights.size();
        int ret=0;
        int i,j;
        for(i=20;i>=0;i--) {
			int tmp=ret+(1<<i);
			if(tmp>=N) continue;
			vector<int> cand;
			FOR(j,tmp) {
				if(heights[j]<heights[j+1]) cand.push_back(heights[j+1]-heights[j]);
			}
			sort(ALL(cand));
			FOR(j,ladders) if(cand.size()) cand.pop_back();
			ll sum=0;
			FORR(a,cand) sum+=a;
			if(sum<=bricks) ret=tmp;
		}
        return ret;
        
        
        
    }
};


