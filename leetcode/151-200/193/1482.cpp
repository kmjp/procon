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
    int minDays(vector<int>& bloomDay, int m, int k) {
		int ok=1<<30;
		int i;
		for(i=29;i>=0;i--) {
			int tmp=ok-(1<<i);
			int num=0;
			int cur=0;
			FORR(b,bloomDay) {
				if(b<=tmp) {
					cur++;
					if(cur>=k) {
						num++;
						cur=0;
					}
				}
				else {
					cur=0;
				}
			}
			if(num>=m) ok=tmp;
		}
		
		if(ok==1<<30) ok=-1;
        return ok;
    }
};

