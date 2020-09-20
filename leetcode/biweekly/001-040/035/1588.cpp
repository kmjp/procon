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
    int sumOddLengthSubarrays(vector<int>& arr) {
		int sum=0;
		int i,j;
		FOR(i,arr.size()) {
			int cur=0;
			for(j=0;i+j<arr.size();j++) {
				cur+=arr[i+j];
				if(j%2==0) sum+=cur;
			}
		}
        return sum;
    }
};

