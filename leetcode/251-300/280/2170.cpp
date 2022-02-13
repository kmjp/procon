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
    int minimumOperations(vector<int>& nums) {
        map<int,int> A[2];
        A[0][0]=A[1][0]=0;
        A[0][-1]=A[1][-1]=0;
        int i;
        FOR(i,nums.size()) A[i%2][nums[i]]++;
        vector<pair<int,int>> V[2];
        FOR(i,2) {
			FORR(a,A[i]) V[i].push_back({a.second,a.first});
			sort(ALL(V[i]));
			reverse(ALL(V[i]));
		}
		
		int mi=1<<20;
		int x,y;
		FOR(x,2) FOR(y,2) if(V[0][x].second!=V[1][y].second) mi=min(mi,(int)nums.size()-V[0][x].first-V[1][y].first);
		return mi;
		
        
        
    }
};
