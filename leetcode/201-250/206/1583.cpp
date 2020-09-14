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


int mat[505][505];

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
		int i,j;
		
		FOR(i,n) {
			FOR(j,n-1) mat[i][preferences[i][j]]=j;
		}
		
		
		int ret=0;
		FORR(p,pairs) {
			FOR(i,2) {
				swap(p[0],p[1]);
				int ok=1;
				FORR(p2,pairs) if(p!=p2) {
					if(mat[p[0]][p2[0]]<mat[p[0]][p[1]] && mat[p2[0]][p[0]]<mat[p2[0]][p2[1]]) ok=0;
					if(mat[p[0]][p2[1]]<mat[p[0]][p[1]] && mat[p2[1]][p[0]]<mat[p2[1]][p2[0]]) ok=0;
				}
				if(ok==0) ret++;
			}
		}
		return ret;
        
    }
};

