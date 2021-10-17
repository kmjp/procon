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
    bool winnerOfGame(string colors) {
		int A=0,B=0;
		char c='Z';
		int num=0;
		FORR(a,colors) {
			if(a==c) {
				num++;
				if(num>=3) {
					if(c=='A') A++;
					else B++;
				}
			}
			else {
				c=a;
				num=1;
			}
		}
        
        return A>=B+1;
    }
};
