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
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		horizontalCuts.push_back(0);
		horizontalCuts.push_back(h);
		verticalCuts.push_back(0);
		verticalCuts.push_back(w);
		sort(ALL(horizontalCuts));
		sort(ALL(verticalCuts));
		int dh=0,dw=0;
		int i;
		FOR(i,horizontalCuts.size()-1) dh=max(dh,horizontalCuts[i+1]-horizontalCuts[i]);
		FOR(i,verticalCuts.size()-1) dw=max(dw,verticalCuts[i+1]-verticalCuts[i]);
        return 1LL*dh*dw%1000000007;
    }
};

