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


int dp[505][505];

class Solution {
public:
	vector<int> A,B;
	int hoge(int x,int y) {
		if(dp[x][y]!=1<<30) return dp[x][y];
		int ret=-(1<<30);
		if(x<A.size()&&y<B.size()) ret=max(ret,A[x]*B[y]+max(0,hoge(x+1,y+1)));
		if(x<A.size()) ret=max(ret,hoge(x+1,y));
		if(y<B.size()) ret=max(ret,hoge(x,y+1));
		return dp[x][y]=ret;
	}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		A=nums1;
		B=nums2;
		int i,j;
		FOR(i,505) FOR(j,505) dp[i][j]=1<<30;
		return hoge(0,0);
    }
};
