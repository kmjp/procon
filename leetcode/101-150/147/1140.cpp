
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

int S[10101];

int dp[101][101][2];

class Solution {
public:
	int N;
	int hoge(int cur,int M,int T) {
		if(dp[cur][M][T]>=0) return dp[cur][M][T];
		if(cur==N) return 0;
		int ret;
		int i;
		
		if(T==0) {
			ret=-(1<<30);
			for(i=1;i<=min(2*M,N-cur);i++) {
				ret=max(ret,S[cur+i]-S[cur]+hoge(cur+i,max(i,M),1));
			}
		}
		else {
			ret=1<<30;
			for(i=1;i<=min(2*M,N-cur);i++) {
				ret=min(ret,hoge(cur+i,max(i,M),0));
			}
		}
		return dp[cur][M][T]=ret;
		
	}


    int stoneGameII(vector<int>& piles) {
		N=piles.size();
		int i,j,x,y;
		FOR(i,N) S[i+1]=S[i]+piles[i];
		MINUS(dp);
		
		return hoge(0,1,0);
		
        
    }
};

