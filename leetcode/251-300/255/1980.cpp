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
    string findDifferentBinaryString(vector<string>& nums) {
		int N=nums[0].size();
		int mask;
		FOR(mask,1<<N) {
			string S;
			int i;
			FOR(i,N) S.push_back('0'+((mask>>i)&1));
			int ok=1;
			FORR(a,nums) if(a==S) ok=0;
			if(ok==1) return S;
			
		}
        return "";
    }
};
