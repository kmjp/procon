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

vector<int> E[1010];
int D[1010];
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
		int ret=1010;
		int i,j,k;
		FOR(i,edges.size()) {
			FOR(j,n) {
				E[j].clear();
				D[j]=1010;
			}
			FOR(j,edges.size()) if(i!=j) {
				E[edges[j][0]].push_back(edges[j][1]);
				E[edges[j][1]].push_back(edges[j][0]);
			}
			queue<int> Q;
			D[edges[i][0]]=0;
			Q.push(edges[i][0]);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FORR(e,E[cur]) if(D[e]==1010) {
					D[e]=D[cur]+1;
					Q.push(e);
				}
			}
			ret=min(ret,D[edges[i][1]]+1);
			
		}
		if(ret>1000) ret=-1;
		return ret;
        
    }
};
