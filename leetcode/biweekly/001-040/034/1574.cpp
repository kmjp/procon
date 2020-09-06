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
    int findLengthOfShortestSubarray(vector<int>& arr) {
		int N=arr.size();
		int i,j,k;
		FOR(i,N-1) if(arr[i]>arr[i+1]) break;
		if(i==N-1) return 0;
		
		j=N-1;
		while(arr[j-1]<=arr[j]) j--;
		int ret=N;
		int pre=-1;
		FOR(k,i+2) {
			while(j<N&&pre>arr[j]) j++;
			ret=min(ret,j-k);
			pre=arr[k];
		}
		return ret;
		
		
    }
};


