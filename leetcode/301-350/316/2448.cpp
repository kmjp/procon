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
    long long minCost(vector<int>& nums, vector<int>& cost) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,nums.size()) V.push_back({nums[i],cost[i]});
		sort(ALL(V));
		ll cur=0;
		ll ac=0;
		ll bc=0;
		FOR(i,nums.size()) {
			cur+=1LL*(V[i].first-V[0].first)*V[i].second;
			if(i==0) ac+=V[i].second;
			else bc+=V[i].second;
		}
		ll ret=cur;
		FOR(i,nums.size()-1) {
			int dif=V[i+1].first-V[i].first;
			cur+=dif*ac;
			cur-=dif*bc;
			ac+=V[i+1].second;
			bc-=V[i+1].second;
			ret=min(ret,cur);
		}
		return ret;
        
    }
};
