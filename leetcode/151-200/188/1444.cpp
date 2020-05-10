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



int H,W,S[101][101];
ll mo=1000000007;
ll memo[51][51][11];

class Solution {
public:
	ll hoge(int H,int W,int k) {
		if(memo[H][W][k]>=0) return memo[H][W][k];
		if(k==1) {
			return S[H][W]>0;
		}
		ll ret=0;
		
		for(int w=1;w<W;w++) {
			if(S[H][w]>0&&S[H][W]-S[H][w]>0) ret+=hoge(H,w,k-1);
		}
		for(int h=1;h<H;h++) {
			if(S[h][W]>0&&S[H][W]-S[h][W]>0) ret+=hoge(h,W,k-1);
		}
		
		
		return memo[H][W][k]=ret%mo;
	}
    int ways(vector<string>& pizza, int k) {
        H=pizza.size();
        W=pizza[0].size();
        reverse(ALL(pizza));
        FORR(p,pizza) reverse(ALL(p));
        ZERO(S);
        int y,x;
        FOR(y,H) FOR(x,W) S[y+1][x+1]=S[y][x+1]+S[y+1][x]-S[y][x]+(pizza[y][x]=='A');
        MINUS(memo);
        
        return hoge(H,W,k);
        
    }
};
