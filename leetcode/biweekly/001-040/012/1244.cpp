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

int SC[10101];
int num[101];
map<int,int> M;

class Leaderboard {
public:
    Leaderboard() {
		M.clear();
        ZERO(SC);
        ZERO(num);
    }
    
    void addScore(int playerId, int score) {
        if(SC[playerId]) M[-SC[playerId]]--;
        SC[playerId]+=score;
        M[-SC[playerId]]++;
    }
    
    int top(int K) {
		int ret=0;
		int i,j;
		FORR(m,M) {
			j=min(K,m.second);
			K-=j;
			ret+=-m.first*j;
		}
        return ret;
    }
    
    void reset(int playerId) {
        if(SC[playerId]) M[-SC[playerId]]--;
        SC[playerId]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
 