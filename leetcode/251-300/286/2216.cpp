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
    int minDeletion(vector<int>& nums) {
		vector<int> A;
		FORR(n,nums) {
			if(A.size()%2==0) {
				A.push_back(n);
			}
			else if(A.back()!=n) {
				A.push_back(n);
			}
		}
		if(A.size()%2) A.pop_back();
        return nums.size()-A.size();
    }
};
