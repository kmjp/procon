
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

int L[101010];
int R[101010];

class Solution {
public:
    int maximumSum(vector<int>& arr) {
		int N=arr.size();
		int ret=-(1<<30);
		int mi=0,sum=0;
		int i;
		FORR(a,arr) {
			sum+=a;
			ret=max(ret,sum-mi);
			mi=min(mi,sum);
		}
		
		mi=0,sum=0;
		FOR(i,N) {
			sum+=arr[i];
			L[i]=sum-mi;
			mi=min(mi,sum);
		}
		mi=0,sum=0;
		for(i=N-1;i>=0;i--) {
			sum+=arr[i];
			R[i]=sum-mi;
			mi=min(mi,sum);
		}
		for(i=1;i<N-1;i++) ret=max(ret,L[i-1]+R[i+1]);
		return ret;
		
        
    }
};

