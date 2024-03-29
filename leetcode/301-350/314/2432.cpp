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
    int hardestWorker(int n, vector<vector<int>>& logs) {
		int id=0;
		int ma=0;
		int pre=0;
		FORR(a,logs) {
			int v=a[1]-pre;
			if(v==ma) {
				id=min(id,a[0]);
			}
			if(v>ma) {
				id=a[0];
				ma=v;
			}
			pre=a[1];
		}
		return id;
        
    }
};
