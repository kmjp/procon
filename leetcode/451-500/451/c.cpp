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


int dp[1010][1010];

class Solution {
public:
    int minMoves(vector<string>& matrix) {
		int H=matrix.size();
		int W=matrix[0].size();
		vector<pair<int,int>> V[26];
		int y,x;
		FOR(y,H) FOR(x,W) {
			if(matrix[y][x]>='A'&&matrix[y][x]<='Z') V[matrix[y][x]-'A'].push_back({y,x});
			dp[y][x]=1<<20;
		}
		dp[0][0]=0;
		deque<int> Q;
		Q.push_back(0);
		while(Q.size()) {
			int cy=Q.front()/1000;
			int cx=Q.front()%1000;
			Q.pop_front();
			if(matrix[cy][cx]>='A'&&matrix[cy][cx]<='Z') {
				FORR(v,V[matrix[cy][cx]-'A']) {
					if(chmin(dp[v.first][v.second],dp[cy][cx])) Q.push_front(v.first*1000+v.second);
				}
				V[matrix[cy][cx]-'A'].clear();
			}
			int i;
			int d[]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W||matrix[ty][tx]=='#') continue;
				if(chmin(dp[ty][tx],dp[cy][cx]+1)) Q.push_back(ty*1000+tx);
			}
		}
		if(dp[H-1][W-1]==1<<20) return -1;
		return dp[H-1][W-1];
		
		
		
        
    }
};


