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
    bool containsPattern(vector<int>& arr, int m, int k) {
		int i,j;
		int N=arr.size();
		for(i=0;i+m*k<=N;i++) {
			FOR(j,m*k) if(arr[i+j]!=arr[i+j%m]) break;
			if(j==m*k) return 1;
			
		}
        return 0;
    }
};

