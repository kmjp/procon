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
    int minimumSwap(string s1, string s2) {
		int num=0;
		int i;
		int A=0,B=0;
		FOR(i,s1.size()) if(s1[i]!=s2[i]) {
			if(s1[i]=='x') A++;
			else B++;
		}
		
		int ret=A/2+B/2;
		A%=2;
		B%=2;
		if(A&&B) {
			ret+=2;
		}
		else if(A||B) {
			return -1;
		}
		return ret;
		
        
    }
};
