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

int R[151][151];

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
		int H=mat.size();
		int W=mat[0].size();
		ZERO(R);
		int x,y,y1;
		FOR(y,H) {
			for(x=W-1;x>=0;x--) {
				R[y][x]=R[y][x+1]+1;
				if(mat[y][x]==0) R[y][x]=0;
			}
		}
		int ret=0;
		FOR(y,H) {
			FOR(x,W) {
				int num=1010;
				for(y1=y;y1<H;y1++) {
					num=min(num,R[y1][x]);
					ret+=num;
				}
			}
		}
        return ret;
    }
};


