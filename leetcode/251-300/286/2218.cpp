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

int ma[2020];

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        ZERO(ma);
        FORR(p,piles) {
			int i,j;
			for(i=k;i>=0;i--) {
				int s=0;
				for(j=0;i+j+1<=k&&j<p.size();j++) {
					s+=p[j];
					ma[i+j+1]=max(ma[i+j+1],ma[i]+s);
				}
			}
		}
		return ma[k];
    }
};
