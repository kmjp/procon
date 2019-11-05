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

int num[50505];

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
		int c=0;
		ll ret=0;
		ZERO(num);
		num[0]=1;
		FORR(n,nums) {
			if(n%2) c++;
			if(c>=k) ret+=num[c-k];
			num[c]++;
		}
		return ret;
		
		
        
    }
};


