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
    bool isRobotBounded(string S) {
		int X=0,Y=0,D=0;
		int dy[4]={0,1,0,-1};
		int dx[4]={1,0,-1,0};
		int i,j;
		FOR(i,10) {
			FORR(c,S) {
				if(c=='G') X+=dx[D],Y+=dy[D];
				if(c=='L') D++;
				if(c=='R') D+=3;
				D%=4;
			}
			if(X==0 && Y==0) return 1;
		}
		return 0;
		
        
    }
};

