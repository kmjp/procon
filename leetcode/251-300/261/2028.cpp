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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
		int sum=0;
		FORR(r,rolls) sum+=r;
		sum=mean*(n+rolls.size())-sum;
		if(sum<n||sum>6*n) return {};
		vector<int> ret(n,1);
		sum-=n;
		FORR(c,ret) {
			int x=min(sum,5);
			c+=x;
			sum-=x;
		}
		return ret;
        
    }
};
