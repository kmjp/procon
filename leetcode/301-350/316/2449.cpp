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
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
		vector<int> C[2],D[2];
		FORR(n,nums) C[n%2].push_back(n/2);
		FORR(n,target) D[n%2].push_back(n/2);
		ll ret=0;
		int i,j;
		FOR(i,2) {
			sort(ALL(C[i]));
			sort(ALL(D[i]));
			FOR(j,C[i].size()) ret+=abs(C[i][j]-D[i][j]);
		}
		return ret/2;
		
        
    }
};
