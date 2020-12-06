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
    string interpret(string S) {
		string T;
		int i;
		FOR(i,S.size()) {
			if(S[i]=='G') {
				T+="G";
			}
			else if(S[i+1]==')') {
				T+="o";
				i++;
			}
			else {
				T+="al";
				i+=3;
			}
		}
		return T;
        
    }
};
