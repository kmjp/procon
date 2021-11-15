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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int pat=0;
        int i;
        while(1) {
	        FOR(i,tickets.size()) {
				if(tickets[i]) {
					tickets[i]--;
					pat++;
					if(i==k&&tickets[i]==0) return pat;
				}
			}
		}
		return 0;
    }
};
