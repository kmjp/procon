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
    long long numberOfWeeks(vector<int>& milestones) {
		ll S=0;
		sort(ALL(milestones));
		FORR(c,milestones) S+=c;
		S-=milestones.back();
		if(S<milestones.back()) {
			return 2*S+1;
		}
		else {
			return S+milestones.back();
		}
        
    }
};
