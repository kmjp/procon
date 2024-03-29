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
    string greatestLetter(string s) {
		string ret="";
		int i;
		FOR(i,26) {
			int ok=0;
			FORR(c,s) {
				if(c=='a'+i) ok|=1;
				if(c=='A'+i) ok|=2;
			}
			if(ok==3) ret='A'+i;
		}
		
		return ret;
        
    }
};
