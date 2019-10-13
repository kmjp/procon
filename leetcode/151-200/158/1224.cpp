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

int C[101010];
map<int,int> M;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
		ZERO(C);
		int ma=0,i;
		M.clear();
		FOR(i,nums.size()) {
			int x=nums[i];
			if(C[x]>0) {
				M[C[x]]--;
				if(M[C[x]]==0) M.erase(C[x]);
			}
			C[x]++;
			M[C[x]]++;
			if(M.size()==1) {
				if(M.begin()->first==1) ma=i+1;
				if(M.begin()->second==1) ma=i+1;
			}
			else if(M.size()==2) {
				if(M.begin()->first==1 && M.begin()->second==1) ma=i+1;
				if(M.rbegin()->first==M.begin()->first+1 && M.rbegin()->second==1) ma=i+1;
			}
			
		}
		return ma;
        
    }
};
