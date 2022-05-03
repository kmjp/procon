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


int C[26];
class Solution {
public:
    long long appealSum(string s) {
		int C[26]={};
		ll ret=0;
		int i,j;
		FOR(i,s.size()) {
			C[s[i]-'a']=i+1;
			FOR(j,26) ret+=C[j];
		}
		
        return ret;
    }
};
