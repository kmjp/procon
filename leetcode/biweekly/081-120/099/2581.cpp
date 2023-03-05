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

int N;
vector<int> E[101010];
int L[101010],R[101010],D[101010];
int id;
int S[101010];

class Solution {
public:

	void dfs(int cur,int pre,int d) {
		L[cur]=id++;
		D[cur]=d;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
		R[cur]=id;
	}
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        N=edges.size()+1;
        int i;
        FOR(i,N) E[i].clear(), S[i]=0;
        
        
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		id=0;
		dfs(0,0,0);
		FORR(g,guesses) {
			int u=g[0];
			int v=g[1];
			if(D[u]<D[v]) {
				S[0]++;
				S[L[v]]--;
				S[R[v]]++;
			}
			else {
				S[L[u]]++;
				S[R[u]]--;
			}
		}
		int sum=0;
		FOR(i,N) {
			if(i) S[i]+=S[i-1];
			if(S[i]>=k) sum++;
		}
		return sum;
		
    }
};
