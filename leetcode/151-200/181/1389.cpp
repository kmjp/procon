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
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> V(index.size());
		int i,j,k;
		FOR(i,index.size()) {
			for(j=index.size()-2;j>=index[i];j--) swap(V[j+1],V[j]);
			V[index[i]]=nums[i];
			
		}
        return V;
    }
};



