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
    int minMoves(int target, int maxDoubles) {
        int num=0;
        while(target>1&&maxDoubles) {
				num++;
			if(target%2==0) {
				target/=2;
				maxDoubles--;
			}
			else {
				target--;
				
			}
			
		}
		return num+target-1;
    }
};
