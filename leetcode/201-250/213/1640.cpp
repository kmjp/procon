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
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		int sum=0;
		FORR(p,pieces) sum+=p.size();
		if(arr.size()!=sum) return 0;
		
		int cur=0;
		while(cur<sum) {
			int ok=0;
			FORR(p,pieces) {
				if(p[0]==arr[cur]&&cur+p.size()<=sum) {
					int i;
					ok=1;
					FOR(i,p.size()) if(p[i]!=arr[cur+i]) ok=0;
					if(ok==1) cur+=p.size();
					break;
				}
			}
			if(ok==0) return 0;
		}
		return 1;
		
        
    }
};

