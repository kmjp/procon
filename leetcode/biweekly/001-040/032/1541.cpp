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
    int minInsertions(string s) {
		int cur=0,ret=0;
		int i;
		FOR(i,s.size()) {
			if(s[i]=='(') {
				cur++;
			}
			else {
				if(cur==0) ret++;
				else cur--;
				if(i+1<s.size()&&s[i+1]==')') i++;
				else ret++;
			}
		}
        ret+=cur*2;
        return ret;
    }
};
