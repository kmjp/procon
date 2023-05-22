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

ll E[101][101];
ll F[101][101];

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int S, int T, int target) {
        ZERO(E);
        FORR(e,edges) {
			E[e[0]][e[1]]=E[e[1]][e[0]]=e[2];
		}
		int x,y,k;
		FOR(y,n) FOR(x,n) {
			F[y][x]=E[y][x];
			if(E[y][x]==-1) F[y][x]=target+1;
			if(E[y][x]==0&&x!=y) F[y][x]=1LL<<40;
		}
		
		FOR(k,n) FOR(x,n) FOR(y,n) F[x][y]=min(F[x][y],F[x][k]+F[k][y]);
		
		if(F[S][T]<target) return {};
		
		int i;
		FORR(e,edges) if(e[2]==-1&&F[S][T]>target) {
			int a=e[0],b=e[1];
			ll d=min(F[S][a]+F[a][b]+F[b][T],F[S][b]+F[b][a]+F[a][T]);
			ll dif=min(d-target,F[a][b]-1);
			if(dif<=0) continue;
			F[a][b]-=dif;
			F[b][a]-=dif;
			FOR(x,n) FOR(y,n) {
				F[x][y]=min(F[x][y],F[x][a]+F[a][b]+F[b][y]);
				F[x][y]=min(F[x][y],F[x][b]+F[b][a]+F[a][y]);
			}
		}
		
		if(F[S][T]!=target) return {};
		FORR(e,edges) if(e[2]==-1) e[2]=F[e[0]][e[1]];
		
		return edges;
    }
};
