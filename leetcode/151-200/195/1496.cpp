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
    bool isPathCrossing(string path) {
		set<pair<int,int>> S;
		S.insert({0,0});
		int x=0,y=0;
		FORR(c,path) {
			if(c=='N') y--;
			if(c=='S') y++;
			if(c=='W') x--;
			if(c=='E') x++;
			if(S.count({x,y})) return 1;
			S.insert({x,y});
		}
        return 0;
    }
};

