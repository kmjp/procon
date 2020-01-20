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




char T[202][202];


class Solution {
public:
    vector<string> printVertically(string s) {
		int ma=0;
		int y=0,x=0;
		vector<string> V;
		ZERO(T);
		FORR(c,s) {
			if(c==' ') {
				y=0;
				x++;
			}
			else {
				T[y][x]=c;
				y++;
			}
		}
		FOR(y,200) {
			int ma=-1;
			FOR(x,202) if(T[y][x]) ma=x;
			FOR(x,ma) if(T[y][x]==0) T[y][x]=' ';
			if(ma>=0) V.push_back(T[y]);
			
		}
        return V;
    }
};




