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
    vector<int> powerfulIntegers(int x, int y, int bound) {
		vector<int> R;
		ll a=1;
		while(a<=bound) {
			ll b=1;
			while(a+b<=bound) {
				R.push_back(a+b);
				if(y==1) break;
				b*=y;
			}
			if(x==1) break;
			a*=x;
		}
		
		sort(ALL(R));
		R.erase(unique(ALL(R)),R.end());
		return R;
        
    }
};
