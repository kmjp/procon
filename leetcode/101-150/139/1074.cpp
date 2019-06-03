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

ll S[303][303];

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int H=matrix.size();
		int W=matrix[0].size();
		int x,y;
		ZERO(S);
		FOR(y,H) FOR(x,W) S[y][x+1]=S[y][x]+matrix[y][x];
		ll ret=0;
		for(int x1=0;x1<W;x1++) {
			for(int x2=x1;x2<W;x2++) {
				map<ll,int> num;
				ll sum=0;
				num[0]=1;
				FOR(y,H) {
					sum+=S[y][x2+1]-S[y][x1];
					ret+=num[sum-target];
					num[sum]++;
				}
				
			}
		}
		return ret;
        
    }
};

