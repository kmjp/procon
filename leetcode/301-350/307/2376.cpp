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
    long long kSum(vector<int>& nums, int k) {
		ll sum=0;
		FORR(n,nums) {
			if(n>0) {
				sum+=n;
				n=-n;
			}
		}
        sort(ALL(nums));
        reverse(ALL(nums));
        if(nums.size()>k) nums.resize(k);
        
        vector<ll> V={0};
		vector<ll> W;
        FORR(v,nums) {
			int a=0,b=0;
			W.clear();
			while((a<V.size()||b<V.size())&&W.size()<k) {
				if(a==V.size()) W.push_back(V[b++]+v);
				else if(b==V.size()) W.push_back(V[a++]);
				else if(V[a]<V[b]+v) W.push_back(V[b++]+v);
				else W.push_back(V[a++]);
			}
			swap(V,W);
		}
        
		return sum+V[k-1];
    }
};
