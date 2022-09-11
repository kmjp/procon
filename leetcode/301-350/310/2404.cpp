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
    int mostFrequentEven(vector<int>& nums) {
		map<int,int> M;
		FORR(n,nums) if(n%2==0) M[n]++;
		int ret=-1;
		int ma=0;
		FORR(a,M) if(a.second>ma) ret=a.first, ma=a.second;
		return ret;
        
    }
};
