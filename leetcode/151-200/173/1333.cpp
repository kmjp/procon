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
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
		vector<pair<int,int>> V;
        FORR(r,restaurants) {
			if(veganFriendly && r[2]==0) continue;
			if(r[3]>maxPrice) continue;
			if(r[4]>maxDistance) continue;
			V.push_back({-r[1],-r[0]});
		}
		sort(ALL(V));
		
		vector<int> W;
		FORR(v,V) W.push_back(-v.second);
		return W;
		
    }
};

