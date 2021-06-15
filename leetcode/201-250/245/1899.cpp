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
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		vector<int> C={0,0,0};
		FORR(t,triplets) {
			if(t[0]>target[0]) continue;
			if(t[1]>target[1]) continue;
			if(t[2]>target[2]) continue;
			C[0]=max(C[0],t[0]);
			C[1]=max(C[1],t[1]);
			C[2]=max(C[2],t[2]);
		}
		return C==target;
        
    }
};
