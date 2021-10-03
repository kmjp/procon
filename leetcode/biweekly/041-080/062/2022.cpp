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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		int x,y;
		vector<vector<int>> R;
		if(m*n!=original.size()) return R;
		FOR(y,m) {
			vector<int> X;
			FOR(x,n) X.push_back(original[y*n+x]);
			R.push_back(X);
		}
		return R;
		
        
    }
};


