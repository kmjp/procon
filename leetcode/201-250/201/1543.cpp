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
    string makeGood(string s) {
		string t;
		
		FORR(c,s) {
			if(t.size()&&t.back()+'A'-'a'==c) {
				t.pop_back();
			}
			else if(t.size()&&t.back()+'a'-'A'==c) {
				t.pop_back();
			}
			else {
				t+=c;
			}
		}
		return t;
        
    }
};

