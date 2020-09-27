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
    int maximumRequests(int n, vector<vector<int>>& requests) {
		int ma=0;
		int N=requests.size();
		int mask,i;
		FOR(mask,1<<N) {
			int dif[20]={};
			FOR(i,N) if(mask&(1<<i)) {
				dif[requests[i][0]]++;
				dif[requests[i][1]]--;
			}
			FOR(i,n) if(dif[i]) break;
			if(i==n) ma=max(ma,__builtin_popcount(mask));
		}
		return ma;
        
    }
};

