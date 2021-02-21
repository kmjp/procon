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
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		int now=0;
		FORR(g,groups) {
			int ok=0;
			int i;
			while(now+g.size()<=nums.size()) {
				FOR(i,g.size()) if(nums[now+i]!=g[i]) break;
				if(i==g.size()) {
					ok=1;
					now+=g.size();
					break;
				}
				now++;
			}
			if(ok==0) return 0;
		}
		return 1;
        
    }
};
