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
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<ll> S;
        S.push_back(0);
        FORR(c,nums) S.push_back(S.back()+c);
        vector<int> ret;
        int i;
        FOR(i,nums.size()) {
			if(i<k||i+k>=nums.size()) {
				ret.push_back(-1);
			}
			else {
				ll v=S[i+k+1]-S[i-k];
				ret.push_back(v/(2*k+1));
			}
		}
		return ret;
    }
};

