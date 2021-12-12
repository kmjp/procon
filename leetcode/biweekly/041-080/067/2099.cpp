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
    vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,nums.size()) {
			V.push_back({-nums[i],i});
		}
		sort(ALL(V));
		V.resize(k);
		vector<int> W;
		FORR(w,V) {
			w={w.second,-w.first};
		}
		sort(ALL(V));
		FORR(w,V) W.push_back(w.second);
		
		return W;
        
    }
};
