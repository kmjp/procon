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
    int minOperations(vector<int>& nums, int x) {
		vector<ll> S;
		S.push_back(0);
		FORR(v,nums) S.push_back(S.back()+v);
		if(S.back()<x) return -1;
		int mi=1<<30,i;
		FOR(i,S.size()) {
			if(i) x-=nums[S.size()-1-i];
			if(x<0) break;
			int y=lower_bound(ALL(S),x)-S.begin();
			if(S[y]==x) mi=min(mi,i+y);
		}
		if(mi==1<<30) mi=-1;
		return mi;
        
    }
};

