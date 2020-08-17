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
    int maxDistance(vector<int>& position, int m) {
        sort(ALL(position));
        int ret=0;
        for(int i=29;i>=0;i--) {
			int tmp=ret+(1<<i);
			int pre=-(1<<30);
			int num=0;
			FORR(p,position) {
				if(p-pre>=tmp) {
					pre=p;
					num++;
				}
			}
			if(num>=m) ret=tmp;
			
		}
        return ret;
        
    }
};


