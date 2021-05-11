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
    int maximumPopulation(vector<vector<int>>& logs) {
		int C[2060]={};
		int i;
		FORR(a,logs) {
			for(i=a[0];i<a[1];i++) {
				C[i]++;
			}
		}
		int ma=0;
		int cur=0;
		FOR(i,2050) {
			if(C[i]>C[ma]) ma=i;
		}
		return ma;
        
    }
};
