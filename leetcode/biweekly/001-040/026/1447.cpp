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
    vector<string> simplifiedFractions(int n) {
		vector<string> R;
		int i,j;
		for(i=1;i<=n;i++) {
			for(j=1;j<i;j++) {
				if(__gcd(i,j)==1) {
					string S=to_string(j)+"/"+to_string(i);
					R.push_back(S);
				}
			}
		}
		return R;
        
    }
};

