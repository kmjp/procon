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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> S,R;
        S.push_back(0);
        FORR(n,nums) S.push_back(S.back()+n);
        int i,N=nums.size();
        FOR(i,N) {
			ll a=S[N]-S[i+1]-nums[i]*(N-(i+1));
			ll b=nums[i]*i-S[i];
			R.push_back(a+b);
		}
		return R;
    }
};

