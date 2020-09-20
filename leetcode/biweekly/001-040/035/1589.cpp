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
int cnt[101010];
const ll mo=1000000007;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
		ZERO(cnt);
		FORR(r,requests) {
			cnt[r[0]]++;
			cnt[r[1]+1]--;
		}
		int i;
		for(i=1;i<nums.size();i++) cnt[i]+=cnt[i-1];
		sort(cnt,cnt+nums.size());
		sort(ALL(nums));
        ll ret=0;
        FOR(i,nums.size()) (ret+=1LL*nums[i]*cnt[i])%=mo;
        return ret;
    }
};

