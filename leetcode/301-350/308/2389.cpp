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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		int mi[1010]={};
		int i;
		FOR(i,1010) mi[i]=1LL<<30;
		int x,y;
		sort(ALL(nums));
		FOR(x,nums.size()) {
			int s=0;
			for(y=0;x+y<nums.size();y++) {
				s+=nums[x+y];
				mi[y+1]=min(mi[y+1],s);
			}
		}
        
        vector<int> V;
        FORR(q,queries) {
			x=0;
			FOR(y,nums.size()+1) if(mi[y]<=q) x=y;
			V.push_back(x);
		}
        return V;
    }
};

