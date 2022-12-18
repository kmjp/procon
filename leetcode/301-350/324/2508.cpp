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


set<int> E[101010];

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        int i;
        FOR(i,n) E[i].clear();
        FORR(e,edges) {
			E[e[0]-1].insert(e[1]-1);
			E[e[1]-1].insert(e[0]-1);
		}
		vector<int> V;
		FOR(i,n) if(E[i].size()%2) V.push_back(i);
		if(V.size()==0) return 1;
		if(V.size()==2) {
			int x=V[0];
			int y=V[1];
			FOR(i,n) if(E[i].count(x)==0&&E[i].count(y)==0) return 1;
			
		}
		if(V.size()==4) {
			do {
				if(E[V[0]].count(V[1])==0&&E[V[2]].count(V[3])==0) return 1;
			} while(next_permutation(ALL(V)));
		}
		return 0;
    }
};
