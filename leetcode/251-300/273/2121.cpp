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


int num[101010];
ll sum[101010];

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
		int i;
		int N=arr.size();
		vector<ll> R(N);
		FOR(i,101000) num[i]=sum[i]=0;
		FOR(i,N) {
			int x=arr[i];
			R[i]+=1LL*num[x]*i-sum[x];
			num[x]++;
			sum[x]+=i;
		}
		FOR(i,101000) num[i]=sum[i]=0;
		for(i=N-1;i>=0;i--) {
			int x=arr[i];
			R[i]+=sum[x]-1LL*num[x]*i;
			num[x]++;
			sum[x]+=i;
		}
		return R;
		
		
        
    }
};
