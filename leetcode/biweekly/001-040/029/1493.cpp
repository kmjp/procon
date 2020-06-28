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
    int longestSubarray(vector<int>& nums) {
		vector<pair<int,int>> V;
		FORR(c,nums) {
			if(V.empty()||V.back().first!=c) V.push_back({c,0});
			V.back().second++;
		}
		
		int ma=0;
		if(V.size()==1) {
			if(V[0].first==0) return 0;
			else return V[0].second-1;
		}
		
		int i;
		FOR(i,V.size()) if(V[i].first==1) {
			ma=max(ma,V[i].second);
			if(i>=2 && V[i-1].second==1) ma=max(ma,V[i].second+V[i-2].second);
			
		}
		return ma;
        
    }
};



