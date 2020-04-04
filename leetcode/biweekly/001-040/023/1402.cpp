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
    int maxSatisfaction(vector<int>& satisfaction) {
		sort(ALL(satisfaction));
		int N=satisfaction.size();
		int ma=0;
		int i,j;
		FOR(i,N) {
			int sum=0;
			for(j=0;i+j<N;j++) {
				sum+=satisfaction[i+j]*(j+1);
				ma=max(ma,sum);
			}
		}
		return ma;
    }
};
