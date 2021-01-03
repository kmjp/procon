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



int C[(1<<21)+1]={};

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        ZERO(C);
        ll ret=0;
        int j;
        FORR(d,deliciousness) {
			for(j=0;j<=21;j++) if(d<=1<<j) ret+=C[(1<<j)-d];
			C[d]++;
		}
		return ret%1000000007;
        
    }
};
