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
    int countVowelStrings(int n) {
		ll ret=0;
		int a,b,c,d;
		FOR(a,n+1) FOR(b,n+1) FOR(c,n+1) FOR(d,n+1) {
			int e=n-a-b-c-d;
			if(e>=0) ret++;
		}
        return ret;
    }
};

