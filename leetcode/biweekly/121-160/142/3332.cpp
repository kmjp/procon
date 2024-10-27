#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int P[505050];
int S[505050];
vector<int> E[505050];
vector<int> E2[505050];
int C[505050];
class Solution {
public:
	void dfs(int cur,vector<int>& V) {
		if(cur) {
			if(V[S[cur]]!=-1) {
				E2[V[S[cur]]].push_back(cur);
			}
			else {
				E2[P[cur]].push_back(cur);
			}
		}
		int pre=V[S[cur]];
		V[S[cur]]=cur;
		FORR(e,E[cur]) dfs(e,V);
		V[S[cur]]=pre;
	}
	int dfs2(int cur) {
		C[cur]=1;
		FORR(e,E2[cur]) C[cur]+=dfs2(e);
		return C[cur];
	}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
		int i;
		int N=parent.size();
		FOR(i,N) {
			E[i].clear(),E2[i].clear();
			S[i]=s[i]-'a';
			P[i]=parent[i];
		}
		FOR(i,N) if(i) E[parent[i]].push_back(i);
		vector<int> V(26,-1);
		dfs(0,V);
		dfs2(0);
		vector<int> R;
		FOR(i,N) R.push_back(C[i]);
		return R;
        
    }
};
