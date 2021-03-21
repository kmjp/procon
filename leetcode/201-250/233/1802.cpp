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
    int maxValue(int n, int index, int maxSum) {
		
		ll ret=0;
		int i;
		for(i=30;i>=0;i--) {
			ll tmp=ret+(1<<i);
			ll L=max(0LL,tmp-index);
			ll sum=(L+tmp)*(tmp-L+1)/2;
			ll R=max(0LL,tmp-(n-1-index));
			sum+=(R+tmp)*(tmp-R+1)/2-tmp;
			
			cout<<L<<" "<<tmp<<" "<<R<<" "<<sum<<endl;
			
			if(sum<=maxSum-n) ret+=1<<i;
		}
		return ret+1;
        
    }
};
