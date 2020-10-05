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
    int specialArray(vector<int>& nums) {
		int C[1010]={};
		int i;
		FORR(n,nums) {
			FOR(i,n+1) C[i]++;
		}
		for(i=0;i<=1000;i++) if(C[i]==i) return i;
		return -1;
        
    }
};

