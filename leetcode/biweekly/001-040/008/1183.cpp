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

int num[101][101];

class Solution {
public:
    int maximumNumberOfOnes(int W, int H, int L, int M) {
		
		ZERO(num);
		int y,x;
		FOR(y,W) FOR(x,H) num[y%L][x%L]++;
		vector<int> C;
		FOR(y,L) FOR(x,L) C.push_back(num[y][x]);
		sort(ALL(C));
		reverse(ALL(C));
		int ret=0;
		FOR(x,M) ret+=C[x];
		return ret;
		
		
        
    }
};