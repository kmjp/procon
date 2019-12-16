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
    vector<int> sequentialDigits(int low, int high) {
        int x,y;
        vector<int> R;
        for(x=1;x<=9;x++) {
			int now=0;
			for(y=x;y<=9;y++) {
				now=now*10+y;
				if(now>=low&&now<=high) R.push_back(now);
			}
		}
		sort(ALL(R));
		return R;
    }
};


