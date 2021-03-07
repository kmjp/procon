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
    int beautySum(string s) {
		int x,y;
		int ret=0;
		FOR(x,s.size()) {
			int C[26]={};
			for(y=x;y<s.size();y++) {
				C[s[y]-'a']++;
				int ma=0,mi=1000;
				int i;
				FOR(i,26) if(C[i]) ma=max(ma,C[i]), mi=min(mi,C[i]);
				ret+=ma-mi;
				
			}
		}
        return ret;
    }
};
