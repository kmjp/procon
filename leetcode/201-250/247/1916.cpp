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

const ll mo=1000000007;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

int C[101010];
ll dp[101010];
vector<int> E[101010];

class Solution {
public:
	ll dfs(int cur) {
		dp[cur]=1;
		C[cur]=0;
		FORR(e,E[cur]) {
			dfs(e);
			dp[cur]=dp[cur]*dp[e]%mo*comb(C[cur]+C[e],C[e])%mo;
			C[cur]+=C[e];
		}
		C[cur]++;
		return dp[cur];
	}
    int waysToBuildRooms(vector<int>& prevRoom) {
        int i;
        FOR(i,prevRoom.size()) E[i].clear();
        FOR(i,prevRoom.size()) {
			if(prevRoom[i]>=0) {
				E[prevRoom[i]].push_back(i);
			}
		}
		return dfs(0);
    }
};
