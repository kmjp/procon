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




class Solution {
public:
    vector<vector<int>> colorGrid(int h, int w, vector<vector<int>>& sources) {
		vector<vector<int>> G;
        G.resize(h);
        FORR(v,G) v.resize(w);
        FORR(a,sources) {
			swap(a[2],a[1]);
			swap(a[1],a[0]);
			G[a[1]][a[2]]=a[0];
		}
		sort(ALL(sources));
		reverse(ALL(sources));
		queue<pair<int,int>> Q;
		FORR(a,sources) Q.push({a[1],a[2]});
		while(Q.size()) {
			int cy=Q.front().first;
			int cx=Q.front().second;
			Q.pop();
			int d[]={0,1,0,-1};
			int i;
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty>=0&&ty<h&&tx>=0&&tx<w&&G[ty][tx]==0) {
					G[ty][tx]=G[cy][cx];
					Q.push({ty,tx});
				}
			}
		}
		return G;
		
    }
};


