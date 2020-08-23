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

int N;
vector<int> S;
ll SS[505];
ll memo[505][505];

class Solution {
public:
	ll hoge(int L,int R) {
		if(L+1>=R) return 0;
		if(memo[L][R]>=0) return memo[L][R];
		
		ll ret=-1;
		int M;
		for(M=L+1;M<R;M++) {
			ll a=SS[M]-SS[L];
			ll b=SS[R]-SS[M];
			
			if(a>=b) ret=max(ret,b+hoge(M,R));
			if(a<=b) ret=max(ret,a+hoge(L,M));
		}
		
		return memo[L][R]=ret;
	}

    int stoneGameV(vector<int>& stoneValue) {
		S=stoneValue;
		N=S.size();
		int i;
		FOR(i,N) SS[i+1]=SS[i]+S[i];
		MINUS(memo);
		
		return hoge(0,N);
		
        
    }
};
