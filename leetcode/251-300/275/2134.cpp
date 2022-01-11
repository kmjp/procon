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
    int minSwaps(vector<int>& nums) {
		int N=nums.size();
		vector<int> S={0};
		int i;
		FOR(i,2*N) {
			S.push_back(S.back()+nums[i%N]);
		}
		int mi=1<<20;
		int num=S[N];
		FOR(i,N) {
			mi=min(mi,num-(S[i+num]-S[i]));
		}
		return mi;
			
        
    }
};
