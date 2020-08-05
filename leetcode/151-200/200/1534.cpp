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
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int ret=0;
		int z,y,x;
		FOR(z,arr.size()) FOR(y,z) FOR(x,y) {
			if(abs(arr[x]-arr[y])<=a &&abs(arr[y]-arr[z])<=b && abs(arr[x]-arr[z])<=c) ret++;
		}
		return ret;
		
        
    }
};

