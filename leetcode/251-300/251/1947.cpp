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
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		int ma=0;
		int M=students.size();
		int N=students[0].size();
		int i;
		vector<int> V;
		FOR(i,M) V.push_back(i);
        do {
			int ret=0;
			int i,j,k;
			FOR(i,M) {
				FOR(j,N) if(students[i][j]==mentors[V[i]][j]) ret++;
			}
			ma=max(ma,ret);
			
		} while(next_permutation(ALL(V)));
		return ma;
    }
};

