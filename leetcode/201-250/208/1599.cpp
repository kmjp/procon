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
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
		
		ll ma=0,cur=0;
		int ret=-1;
		
		int i;
		int num=0;
		FOR(i,5000001) {
			if(i<customers.size()) {
				num+=customers[i];
			}
			else if(num==0) break;
			
			int x=min(4,num);
			cur+=x*boardingCost;
			num-=x;
			cur-=runningCost;
			
			if(cur>ma) ma=cur, ret=i+1;
			
			
		}
		return ret;
		
        
    }
};
