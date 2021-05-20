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
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		vector<vector<char>> T;
		int H=box.size(),W=box[0].size(),x,y;
		T.resize(W);
		FOR(y,W) T[y].resize(H);
		FOR(y,H) FOR(x,W) T[x][H-1-y]=box[y][x]; //left
        swap(H,W);
        FOR(x,W) {
			for(y=H-1;y>=0;y--) {
				int sy=y;
				while(T[sy][x]=='#'&&sy+1<H&&T[sy+1][x]=='.') {
					swap(T[sy][x],T[sy+1][x]);
					sy++;
				}
			}
		}
		return T;
    }
};

