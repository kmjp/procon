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


vector<int> E[101010];
vector<int> O,S;

class Solution {
public:
	int dfs(int cur) {
		if(E[cur].empty()) {
			return S[cur];
		}
		vector<int> V;
		FORR(e,E[cur]) V.push_back(dfs(e));
		sort(ALL(V));
		if(O[cur]==0) {
			if(V[0]<0) V[0]=0;
		}
		else {
			V[0]=0;
		}
		int ret=S[cur];
		FORR(v,V) ret+=v;
		return ret;
	}
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
		int N=parent.size();
		int i;
		FOR(i,N) E[i].clear();
		O=op;
		S=score;
		FOR(i,N) if(parent[i]>=0) E[parent[i]].push_back(i);
		return dfs(0);
        
    }
};


