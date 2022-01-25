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
    int maximumGood(vector<vector<int>>& statements) {
		int N=statements.size();
		int ma=0;
		int mask;
		FOR(mask,1<<N) {
			int num=__builtin_popcount(mask);
			if(num<=ma) continue;
			int ok=1;
			int x,y;
			FOR(x,N) FOR(y,N) if(statements[x][y]!=2) {
				int xg=(mask>>x)&1;
				int yg=(mask>>y)&1;
				if(xg&&yg!=statements[x][y]) ok=0;
			}
			
			if(ok) ma=num;
		}
		return ma;
        
    }
};
