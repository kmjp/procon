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

vector<pair<int,int>> E[101010];


class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
		int N=scores.size();
		int i;
		FOR(i,N) E[i].clear();
		FORR(a,edges) {
			E[a[0]].push_back({scores[a[1]],a[1]});
			E[a[1]].push_back({scores[a[0]],a[0]});
		}
		FOR(i,N) {
			sort(ALL(E[i]));
			reverse(ALL(E[i]));
		}
		int ma=-1;
		FOR(i,N) FORR(e,E[i]) {
			int v=e.second;
			int x,y;
			FOR(x,min((int)E[i].size(),3)) {
				FOR(y,min((int)E[v].size(),3)) {
					if(E[i][x].second==v) continue;
					if(E[v][y].second==i) continue;
					if(E[i][x].second==E[v][y].second) continue;
					ma=max(ma,scores[i]+scores[v]+E[i][x].first+E[v][y].first);
				}
			}
		}
		
		return ma;
			
        
    }
};
