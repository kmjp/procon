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
    int countNicePairs(vector<int>& nums) {
		map<int,int> M;
		ll ret=0;
		FORR(x,nums) {
			int y=0,v=x;
			while(v) {
				y=y*10+v%10;
				v/=10;
			}
			y-=x;
			ret+=M[y];
			M[y]++;
		}
		
		
		return ret%1000000007;
        
    }
};
