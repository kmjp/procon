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

int E[101010];
vector<int> RE[101010];
int vis[101010];

class Solution {
public:
	int dfs(int cur,int d) {
		if(vis[cur]==-2) return 0;
		if(vis[cur]!=-1) {
			return d-vis[cur];
		}
		vis[cur]=d;
		int ret=dfs(E[cur],d+1);
		vis[cur]=-2;
		return ret;
	}
	
	int dfs2(int cur,int pre,int d) {
		int ma=d;
		FORR(e,RE[cur]) if(e!=pre) ma=max(ma,dfs2(e,cur,d+1));
		return ma;
	}

    int maximumInvitations(vector<int>& favorite) {
        int N=favorite.size();
        int i;
        FOR(i,N) {
			E[i]=favorite[i];
			RE[i].clear();
			vis[i]=-1;
		}
        FOR(i,N) {
			RE[E[i]].push_back(i);
		}
		int ma=0;
		FOR(i,N) if(vis[i]==-1) {
			ma=max(ma,dfs(i,0));
		}
		int sum=0;
		FOR(i,N) if(E[E[i]]==i&&i<E[i]) {
			sum+=dfs2(i,E[i],1);
			sum+=dfs2(E[i],i,1);
		}
		return max(ma,sum);
    }
};
