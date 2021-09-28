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
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int H=board.size();
        int W=board[0].size();
        int y,x,i;
        FOR(i,2) {
			reverse(ALL(word));
			FOR(y,H) {
				set<int> S;
				S.insert(-1);
				S.insert(W);
				FOR(x,W) if(board[y][x]=='#') S.insert(x);
				
				auto it=S.begin();
				while(*it!=W) {
					int x1=*it;
					int x2=*next(it);
					it++;
					if(x2-x1-1!=word.size()) continue;
					int ok=1;
					for(x=x1+1;x<x2;x++) {
						if(board[y][x]!=' '&&board[y][x]!=word[x-(x1+1)]) ok=0;
					}
					if(ok) return 1;
				}
			}
			FOR(x,W) {
				set<int> S;
				S.insert(-1);
				S.insert(H);
				FOR(y,H) if(board[y][x]=='#') S.insert(y);
				
				auto it=S.begin();
				while(*it!=H) {
					int y1=*it;
					int y2=*next(it);
					it++;
					if(y2-y1-1!=word.size()) continue;
					int ok=1;
					for(y=y1+1;y<y2;y++) {
						if(board[y][x]!=' '&&board[y][x]!=word[y-(y1+1)]) ok=0;
					}
					if(ok) return 1;
				}
			}
		}
		
		return 0;
        
    }
};
