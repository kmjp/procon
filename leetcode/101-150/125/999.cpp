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
    int numRookCaptures(vector<vector<char>>& B) {
		int y,x;
		FOR(y,8) FOR(x,8) if(B[y][x]=='R') {
			int num=0;
			int i;
			FOR(i,4) {
				int d[4]={0,1,-1,0};
				int cy=y+d[i];
				int cx=x+d[i^1];
				
				while(1) {
					if(cy<0||cy>=8||cx<0||cx>=8) break;
					if(B[cy][cx]=='B') break;
					if(B[cy][cx]=='p') {
						num++;
						break;
					}
					cy+=d[i];
					cx+=d[i^1];
				}
				
			}
			return num;
		}
		return 0;
        
    }
};
