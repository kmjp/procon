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
    int minAbsDifference(vector<int>& nums, int goal) {
		int S=nums.size()/2,T=nums.size()-S;
        vector<ll> A;
        int mask,i;
        FOR(mask,1<<T) {
			ll tot=0;
			FOR(i,T) if(mask&(1<<i)) tot+=nums[i];
			A.push_back(tot);
		}
		sort(ALL(A));
		A.erase(unique(ALL(A)),A.end());
		ll ret=abs(goal);
        FOR(mask,1<<S) {
			ll tot=0;
			FOR(i,S) if(mask&(1<<i)) tot+=nums[i+T];
			ll target=goal-tot;
			int x=lower_bound(ALL(A),target)-A.begin();
			for(int y=x-1;y<=x+1;y++) {
				if(y>=0&&y<A.size()) ret=min(ret,abs(goal-(tot+A[y])));
			}
		}
		return ret;
		
    }
};
