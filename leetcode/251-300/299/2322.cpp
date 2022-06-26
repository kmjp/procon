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

int V[1010];
vector<int> E[1010];
int X[1010];
int L[1010],R[1010];
int id;
int N;
class Solution {
public:
	int dfs(int cur,int pre) {
		X[cur]=V[cur];
		L[cur]=id++;
		FORR(e,E[cur]) if(e!=pre) {
			X[cur]^=dfs(e,cur);
		}
		R[cur]=id;
		return X[cur];
	}
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int N=nums.size();
        int i;
        FOR(i,N) {
			V[i]=nums[i];
			E[i].clear();
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]),E[e[1]].push_back(e[0]);
		}
		id=0;
		dfs(0,0);
		int ret=1<<30;
		FORR(e,edges) {
			if(L[e[0]]>L[e[1]]) swap(e[0],e[1]);
		}
		FORR(e1,edges) FORR(e2,edges) if(e1<e2) {
			int a,b,c,d;
			if(L[e1[1]]<=L[e2[0]]&&L[e2[0]]<R[e1[1]]) {
				c=X[e2[1]];
				b=X[e1[1]]^c;
				a=X[0]^X[e1[1]];
				d=0;
			}
			else if(L[e2[1]]<=L[e1[0]]&&L[e1[0]]<R[e2[1]]) {
				c=X[e1[1]];
				b=X[e2[1]]^c;
				a=X[0]^X[e2[1]];
				d=1;
			}
			else {
				c=X[e1[1]];
				b=X[e2[1]];
				a=X[0]^b^c;
				d=2;
			}
			ret=min(ret,max({a,b,c})-min({a,b,c}));
		}
		return ret;

		
    }
};
