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
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> R(N);
		vector<vector<int>> E(N);
		FORR(p,paths) {
			E[p[0]-1].push_back(p[1]-1);
			E[p[1]-1].push_back(p[0]-1);
		}
		int i;
		
		FOR(i,N) {
			int mask=0;
			FORR(e,E[i]) if(R[e]!=0) mask|=1<<(R[e]-1);
			if((mask&1)==0) R[i]=1;
			if((mask&2)==0) R[i]=2;
			if((mask&4)==0) R[i]=3;
			if((mask&8)==0) R[i]=4;
		}
		return R;
        
    }
};

