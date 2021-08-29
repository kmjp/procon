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
    string kthLargestNumber(vector<string>& nums, int k) {
		vector<string> V[101];
		FORR(n,nums) V[n.size()].push_back(n);
		int i;
		for(i=100;i>=0;i--) {
			if(k<=V[i].size()) {
				sort(ALL(V[i]));
				reverse(ALL(V[i]));
				return V[i][k-1];
			}
			else {
				k-=V[i].size();
			}
		}
        return "";
    }
};

