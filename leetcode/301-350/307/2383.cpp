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
    int minNumberOfHours(int X, int Y, vector<int>& energy, vector<int>& experience) {
        int add=0;
        int i;
        FOR(i,energy.size()) {
			if(X<=energy[i]) {
				add+=energy[i]+1-X;
				X+=energy[i]+1-X;
			}
			if(Y<=experience[i]) {
				add+=experience[i]+1-Y;
				Y+=experience[i]+1-Y;
			}
			X-=energy[i];
			Y+=experience[i];
			
		}
		return add;
    }
};
