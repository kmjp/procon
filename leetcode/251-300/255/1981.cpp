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


int from[5050];
int to[5050];

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		int H=mat.size();
		int W=mat[0].size();
		ZERO(from);
		from[0]=1;
			int i;
		FORR(v,mat) {
			ZERO(to);
			FORR(a,v) {
				FOR(i,5000) if(from[i]) to[i+a]=1;
			}
			swap(from,to);
		}
		int mi=101010;
		FOR(i,5050) if(from[i]) mi=min(mi,abs(target-i));
		return mi;
		
        
    }
};
