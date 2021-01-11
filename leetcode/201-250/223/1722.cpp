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
int vis[101010];
vector<int> S,T,A,B;
class Solution {
public:
	void dfs(int cur) {
		vis[cur]=1;
		A.push_back(S[cur]);
		B.push_back(T[cur]);
		FORR(e,E[cur]) if(vis[e]==0) dfs(e);
	}
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int i;
        int N=source.size();
        FOR(i,N) E[i].clear(),vis[i]=0;
        FORR(s,allowedSwaps) E[s[0]].push_back(s[1]),E[s[1]].push_back(s[0]);
        S=source;
        T=target;
        int ret=0;
        FOR(i,N) if(vis[i]==0) {
			A.clear();
			B.clear();
			dfs(i);
			sort(ALL(A));
			sort(ALL(B));
			A.push_back(1000000);
			B.push_back(1000000);
			int x=0,y=0;
			while(x<A.size()||y<B.size()) {
				if(A[x]==B[y]) {
					x++,y++;
				}
				else if(A[x]<B[y]) {
					x++;
					ret++;
				}
				else {
					y++;
				}
			}
		}
        return ret;
    }
};



