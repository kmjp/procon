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

int H[101010];
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
		int i;
		restrictions.push_back({1,0});
		sort(ALL(restrictions));
		if(restrictions.back()[0]!=n) restrictions.push_back({n,1<<30});
		int ma=0;
		FOR(i,restrictions.size()-1) {
			restrictions[i+1][1]=min(restrictions[i+1][1],restrictions[i][1]+(restrictions[i+1][0]-restrictions[i][0]));
		}
		for(i=restrictions.size()-2;i>=0;i--) {
			restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+(restrictions[i+1][0]-restrictions[i][0]));
		}
		FORR(r,restrictions) ma=max(ma,r[1]);
		FOR(i,restrictions.size()-1) {
			int a=restrictions[i][1];
			int b=restrictions[i+1][1];
			int c=restrictions[i+1][0]-restrictions[i][0];
			if(a>b) swap(a,b);
			c-=(b-a);
			ma=max(ma,b+c/2);
		}
		
		return ma;
        
    }
};
