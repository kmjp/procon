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
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> M;
        FORR(a,nums) M[a]++;
        while(M.size()) {
			int x=M.begin()->first;
			for(int i=0;i<k;i++) {
				if(M.count(x+i)==0) return false;
				M[x+i]--;
				if(M[x+i]==0) M.erase(x+i);
			}
			
		}
		return M.empty();
    }
};

