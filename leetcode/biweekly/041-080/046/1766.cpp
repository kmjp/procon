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

vector<int> E[101010];
vector<int> V;
vector<int> R;
vector<int> D;

vector<int> A[61];
class Solution {
public:
	void dfs(int cur,int pre,int d) {
		int i;
		D[cur]=d;
		R[cur]=-1;
		for(i=1;i<=50;i++) if(__gcd(V[cur],i)==1&&A[i].size()) {
			int x=A[i].back();
			if(R[cur]==-1) R[cur]=x;
			else if(D[R[cur]]<D[x]) R[cur]=x;
		}
		A[V[cur]].push_back(cur);
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
		A[V[cur]].pop_back();
		
	}
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
		D=R=V=nums;
		int N=nums.size();
		int i;
		FOR(i,N) E[i].clear();
		FOR(i,51) A[i].clear();
		FORR(e,edges) E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
        dfs(0,0,0);
        return R;
    }
};
