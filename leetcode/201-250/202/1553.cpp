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

map<int,int> memo;

class Solution {
public:
    int minDays(int n) {
		if(n==0) return 0;
		if(memo.count(n)) return memo[n];
		
		int ret=n;
		ret=min({n,n%2+1+minDays(n/2),n%3+1+minDays(n/3)});
		return memo[n]=ret;
    }
};

