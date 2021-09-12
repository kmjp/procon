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
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
		map<pair<int,int>,int> M;
		ll ret=0;
		FORR(a,rectangles) {
			int x=a[0];
			int y=a[1];
			int g=__gcd(x,y);
			x/=g;
			y/=g;
			ret+=M[{x,y}];
			M[{x,y}]++;
			
		}
        return ret;
    }
};
