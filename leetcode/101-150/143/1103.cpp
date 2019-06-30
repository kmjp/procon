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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> R(num_people);
        int nex=1;
        int i;
        while(candies) {
			FOR(i,num_people) {
				int mi=min(candies,nex);
				R[i]+=mi;
				candies-=mi;
				nex++;
			}
		}
        return R;
        
    }};

