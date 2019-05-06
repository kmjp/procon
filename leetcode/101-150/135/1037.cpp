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
    bool isBoomerang(vector<vector<int>>& P) {
		if(P[0]==P[1]) return 0;
		if(P[1]==P[2]) return 0;
		if(P[2]==P[0]) return 0;
		
		return (P[0][0]-P[1][0])*(P[2][1]-P[1][1])!=(P[0][1]-P[1][1])*(P[2][0]-P[1][0]);
        
    }
};

