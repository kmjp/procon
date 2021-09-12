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

ll dp[101010];
ll S[101010];
const ll mo=1000000007;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& V) {
        int N=V.size();
        int i;
        dp[0]=S[0]=2;
        for(i=1;i<N;i++) {
			dp[i]=(2+mo+S[i-1]-(V[i]==0?0:S[V[i]-1]))%mo;
			S[i]=dp[i];
			if(i) (S[i]+=S[i-1])%=mo;
		}
		return S[N-2];
    }
};
