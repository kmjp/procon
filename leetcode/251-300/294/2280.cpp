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
    int minimumLines(vector<vector<int>>& stockPrices) {
		sort(ALL(stockPrices));
		int N=stockPrices.size();
		int ret=N-1;
		int i;
		FOR(i,N-2) {
			ll ax=stockPrices[i+1][0]-stockPrices[i][0];
			ll ay=stockPrices[i+1][1]-stockPrices[i][1];
			ll bx=stockPrices[i+2][0]-stockPrices[i][0];
			ll by=stockPrices[i+2][1]-stockPrices[i][1];
			if(ax*by==ay*bx) ret--;
		}
		return ret;
        
    }
};
