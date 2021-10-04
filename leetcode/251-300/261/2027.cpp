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
    int minimumMoves(string s) {
        s+="OO";
        int i;
        int ret=0;
        FOR(i,s.size()-2) if(s[i]=='X') {
			ret++;
			s[i]=s[i+1]=s[i+2]='O';
		}
		return ret;
    }
};
