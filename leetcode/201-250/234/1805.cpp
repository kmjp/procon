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
    int numDifferentIntegers(string word) {
        word+="a";
        int cur=-1;
        set<string> S;
        string T;
        FORR(c,word) {
			if(c>='0'&&c<='9') {
				T+=c;
			}
			else {
				if(T.size()) {
					reverse(ALL(T));
					while(T.size()&&T.back()=='0') T.pop_back();
					S.insert(T);
				}
				T="";
			}
		}
		return S.size();
    }
};