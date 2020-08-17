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
    bool threeConsecutiveOdds(vector<int>& arr) {
		int cur=0;
		FORR(a,arr) {
			if(a%2==0) cur=0;
			else cur++;
			if(cur>=3) return 1;
		}
		return 0;
		
        
    }
};


