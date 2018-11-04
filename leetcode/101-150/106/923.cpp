typedef signed long long ll;

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

int num[303];

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
		int N=A.size();
		int y,x;
		ll ret=0;
		FOR(x,N) {
			ZERO(num);
			for(y=N-1;y>=x+1;y--) {
				if(A[x]+A[y]<=target) ret+=num[target-A[x]-A[y]];
				num[A[y]]++;
			}
		}
		return ret%1000000007;
        
    }
};
