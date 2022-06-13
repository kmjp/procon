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
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int pre=0;
        double ret=0;
        FORR(v,brackets) {
			int num=min(income,v[0])-pre;
			if(num>0) {
				ret+=num*v[1]/100.0;
			}
			pre=v[0];
        }
        return ret;
    }
};
