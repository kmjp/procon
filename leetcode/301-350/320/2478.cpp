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


ll from[1010],to[1010];
const ll mo=1000000007;

class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
		FORR(c,s) {
			if(c=='2'||c=='3'||c=='7'||c=='5') c=0;
			else c=1;
		}
		ZERO(from);
		from[0]=1;
		int i;
		while(k--) {
			ZERO(to);
			
			ll sum=0;
			FOR(i,s.size()) {
				if(i>=minLength-1&&s[i-(minLength-1)]==0) {
					(sum+=from[i-(minLength-1)])%=mo;
				}
				if(s[i]) {
					to[i+1]=sum;
				}
			}
			
			swap(from,to);
		}
		return from[s.size()];
    }
};

