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
    double probabilityOfHeads(vector<double>& prob, int target) {
		int N=prob.size();
		double from[1010]={};
		from[0]=1;
		int i;
		FORR(p,prob) {
			double to[1010]={};
			
			FOR(i,N) {
				to[i]+=from[i]*(1-p);
				to[i+1]+=from[i]*(p);
			}
			
			swap(from,to);
			
		}
        return from[target];
    }
};


