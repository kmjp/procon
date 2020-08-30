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
    int getMaxLen(vector<int>& nums) {
		int C[2]={};
		int ma=0;
		FORR(n,nums) {
			if(n==0) {
				C[0]=C[1]=0;
			}
			else if(n>0) {
				C[0]++;
				if(C[1]) C[1]++;
			}
			else {
				swap(C[0],C[1]);
				if(C[0]) C[0]++;
				C[1]++;
			}
			ma=max(ma,C[0]);
		}
		return ma;
        
    }
};

