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
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		map<int,int> mask;
		FORR(r,reservedSeats) mask[r[0]] |= 1<<(r[1]-1);
		
		ll ret=n*2;
		FORR(m,mask) {
			int x=m.second;
			int i;
			ret-=2;
			if((x&((15<<1)|(15<<5)))==0) {
				ret+=2;
			}
			else if((x&(15<<1))==0) {
				ret++;
			}
			else if((x&(15<<5))==0) {
				ret++;
			}
			else if((x&(15<<3))==0) {
				ret++;
			}
		}
        return ret;
    }
};


