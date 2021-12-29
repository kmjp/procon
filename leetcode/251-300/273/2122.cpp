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

int vis[2020];

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
		int N=nums.size()/2;
		sort(ALL(nums));
		int x,y;
		for(x=1;x<=N;x++) {
			
			int d=nums[x]-nums[0];
			if(d%2||d==0) continue;
			vector<int> C;
			ZERO(vis);
			int L=0,R=0;
			FOR(L,2*N) {
				if(vis[L]) continue;
				while(R<2*N&&nums[R]<nums[L]+d) R++;
				if(R==2*N||nums[R]!=nums[L]+d) {
					break;
				}
				vis[R]=1;
				R++;
				C.push_back(nums[L]+d/2);
			}
			
			if(C.size()==N) return C;
			
		}
		return {};
        
    }
};
