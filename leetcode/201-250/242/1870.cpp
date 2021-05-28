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
    int minSpeedOnTime(vector<int>& dist, double hour) {
		int ret=10101011;
		int i,j;
		ll a=round(hour*100);
		for(i=25;i>=0;i--) {
			int tmp=ret-(1<<i);
			if(tmp<=0) continue;
			
			ll sum=0;
			FOR(j,dist.size()-1) {
				sum+=(dist[j]+tmp-1)/tmp;
			}
			
			
			if(a-sum*100>=(dist.back()*100+tmp-1)/tmp) ret=tmp;
			
		}
		
		
		
		if(ret>=10000001) ret=-1;
		return ret;
        
    }
};
