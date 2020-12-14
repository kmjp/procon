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

int dp[1010][1010];

class Solution {
public:
	vector<int> S,T;
	
	int hoge(int L,int R) {
		if(L>=R) return 0;
		if(L+1==R) return 0;
		
		if(dp[L][R]!=1<<30) return dp[L][R];
		dp[L][R]=max(T[R]-T[L+1]-hoge(L+1,R),T[R-1]-T[L]-hoge(L,R-1));
		return dp[L][R];
		
	}
	
    int stoneGameVII(vector<int>& stones) {
        int N=stones.size();
        int x,y;
        FOR(x,N+1) FOR(y,N+1) dp[x][y]=1<<30;
        S=stones;
        T.clear();
        T.push_back(0);
        FORR(c,S) T.push_back(T.back()+c);
        return hoge(0,N);
    }
};
