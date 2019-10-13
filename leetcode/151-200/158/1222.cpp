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

int B[8][8];


class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		int KY=king[0], KX=king[1];
		ZERO(B);
		FORR(q,queens) B[q[0]][q[1]]=1;
		int ret=0,x,y;
		vector<vector<int>> R;
		for(x=KX;x<8;x++) if(B[KY][x]==1) {
			R.push_back({KY,x});
			break;
		}
		for(x=KX;x<8;x++) if(KY+x-KX<8 && KY+x-KX>=0 && B[KY+x-KX][x]==1) {
			R.push_back({KY+x-KX,x});
			break;
		}
		for(x=KX;x<8;x++) if(KY+KX-x>=0 && KY+KX-x<8 && B[KY+KX-x][x]==1) {
			R.push_back({KY+KX-x,x});
			break;
		}
		for(x=KX-1;x>=0;x--) if(B[KY][x]==1) {
			R.push_back({KY,x});
			break;
		}
		for(x=KX-1;x>=0;x--)  if(KY+x-KX<8 && KY+x-KX>=0 && B[KY+x-KX][x]==1) {
			R.push_back({KY+x-KX,x});
			break;
		}
		for(x=KX-1;x>=0;x--)  if(KY+KX-x>=0 && KY+KX-x<8 && B[KY+KX-x][x]==1) {
			R.push_back({KY+KX-x,x});
			break;
		}
		for(y=KY-1;y>=0;y--) if(B[y][KX]==1) {
			R.push_back({y,KX});
			break;
			
		}
		for(y=KY+1;y<8;y++) if(B[y][KX]==1) {
			R.push_back({y,KX});
			break;
		}
		
		return R;
		
		
        
    }
};
