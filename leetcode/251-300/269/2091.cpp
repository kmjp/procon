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
    int minimumDeletions(vector<int>& nums) {
        int x=min_element(ALL(nums))-nums.begin();
        int y=max_element(ALL(nums))-nums.begin();
        if(x>y) swap(x,y);
        int ret=min({x+1+(int)nums.size()-y,y+1,(int)nums.size()-x});
        return ret;
    }
};

