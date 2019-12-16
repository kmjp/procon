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



ll S[303][303];

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        ZERO(S);
        int H=mat.size();
        int W=mat[0].size();
        int y,x,i;
        FOR(y,H) FOR(x,W) {
			S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+mat[y][x];
		}
		int ma=0;
		FOR(y,H) FOR(x,W) for(i=1;y+i<=H && x+i<=W;i++) {
			if(S[y+i][x+i]-S[y][x+i]-S[y+i][x]+S[y][x]<=threshold) ma=max(ma,i);
		}
		return ma;
        
    }
};
