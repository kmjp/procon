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
	int ok(int n) {
		while(n) {
			if(n%10==0) return 0;
			n/=10;
		}
		return 1;
	}
    vector<int> getNoZeroIntegers(int n) {
		int i;
		for(i=1;i<n;i++) {
			if(ok(i) && ok(n-i)) return {i,n-i};
		}
		return {};
    }
};
