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
    long long totalCost(vector<int>& costs, int k, int candidates) {
		int L=0,R=costs.size()-1;
		set<pair<int,int>> S;
		int i;
		ll ret=0;
		FOR(i,candidates) if(L<=R) {
			S.insert({costs[L],L});
			L++;
		}
		FOR(i,candidates) if(L<=R) {
			S.insert({costs[R],R});
			R--;
		}
		while(k--) {
			int cur=S.begin()->second;
			ret+=S.begin()->first;
			S.erase(S.begin());
			if(cur<L&&L<=R) {
				S.insert({costs[L],L});
				L++;
			}
			else if(cur>R&&L<=R) {
				S.insert({costs[R],R});
				R--;
			}
		}
        return ret;
    }
};
