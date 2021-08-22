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
    int minTimeToType(string word) {
		int cur=0;
		int ret=0;
		FORR(c,word) {
			c-='a';
			int cost=100;
			if(c<=cur) {
				cost=min(cost,cur-c);
				cost=min(cost,c-(cur-26));
			}
			else {
				cost=min(cost,c-cur);
				cost=min(cost,cur-c+26);
			}
			ret+=cost;
			cur=c;
			
		}
        return ret+word.size();
        
    }
};
