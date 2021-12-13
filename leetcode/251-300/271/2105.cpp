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
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		
		int A=capacityA,B=capacityB;
		int ret=0;
		for(int L=0,R=plants.size()-1;L<=R;L++,R--) {
			if(L!=R) {
				if(A<plants[L]) {
					ret++;
					A=capacityA;
				}
				A-=plants[L];
				if(B<plants[R]) {
					ret++;
					B=capacityB;
				}
				B-=plants[R];
			}
			else {
				if(max(A,B)<plants[L]) {
					ret++;
				}
			}
		}
        return ret;
    }
};


