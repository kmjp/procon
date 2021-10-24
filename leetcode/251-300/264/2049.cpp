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

int C[101010];
int N;
vector<int> E[101010];
int P[101010];
ll ret;
int num;
class Solution {
public:
	int dfs(int cur) {
		C[cur]=1;
		FORR(e,E[cur]) C[cur]+=dfs(e);
		return C[cur];
	}
	void dfs2(int cur) {
		ll pat=1;
		if(cur==0) {
			FORR(e,E[cur]) pat*=C[e];
		}
		else {
			pat=N-C[cur];
			FORR(e,E[cur]) pat*=C[e];
		}
		if(ret<pat) num=0;
		ret=max(ret,pat);
		if(ret==pat) num++;
		FORR(e,E[cur]) dfs2(e);
	}
    int countHighestScoreNodes(vector<int>& parents) {
		N=parents.size();
		int i;
		FOR(i,N) C[i]=0,E[i].clear();
		for(i=N-1;i>=0;i--) {
			if(i) {
				C[parents[i]]+=C[i];
				E[parents[i]].push_back(i);
				P[i]=parents[i];
			}
		}
		ret=num=0;
		dfs(0);
		dfs2(0);
        return num;
    }
};
