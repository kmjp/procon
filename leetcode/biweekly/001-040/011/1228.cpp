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
    int missingNumber(vector<int>& arr) {
		int mi=1<<30;
		int i;
		FOR(i,arr.size()-1) {
			int d=abs(arr[i]-arr[i+1]);
			if(d<mi) mi=d;
		}
		FOR(i,arr.size()-1) {
			if(abs(arr[i]-arr[i+1])!=mi) {
				return (arr[i]+arr[i+1])/2;
			}
		}
		return arr[0];
        
    }
};

