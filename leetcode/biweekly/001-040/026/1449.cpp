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

int num[5050];
int from[5050];

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
		int x,y,i;
		
		FOR(x,5010) num[x]=-(1<<30);
		num[0]=0;
		FOR(x,target) if(num[x]>=0) {
			FOR(i,9) if(x+cost[i]<=target) num[x+cost[i]]=max(num[x+cost[i]],num[x]+1);
		}
		
		if(num[target]<0) return "0";
		
		string S;
		while(target>0) {
			int x=-1;
			for(i=8;i>=0;i--) if(cost[i]<=target && num[target-cost[i]]>=0) {
				if(x==-1 || num[target-cost[i]]>num[target-cost[x]]) x=i;
			}
			target-=cost[x];
			S+='1'+x;
		}
		
		return S;
		
        
    }
};
