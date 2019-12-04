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
    string tictactoe(vector<vector<int>>& moves) {
		char A[3][4]={};
		int i;
		FOR(i,moves.size()) {
			A[moves[i][0]][moves[i][1]]='A'+(i%2);
		}
		cout<<A[0]<<endl;
		cout<<A[1]<<endl;
		cout<<A[2]<<endl;
		int x,y;
		FOR(y,3) {
			if(A[y][0]==A[y][1]&&A[y][0]==A[y][2]&&A[y][0]!=0) return string(1,A[y][0]);
			if(A[0][y]==A[1][y]&&A[0][y]==A[2][y]&&A[0][y]!=0) return string(1,A[0][y]);
		}
		if(A[0][0]==A[1][1]&&A[0][0]==A[2][2]&&A[0][0]!=0) return string(1,A[0][0]);
		if(A[0][2]==A[1][1]&&A[0][2]==A[2][0]&&A[0][2]!=0) return string(1,A[0][2]);
		
		if(moves.size()==9) return "Draw";
		return "Pending";
		
        
    }
};
