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

ll X[404],Y[404];
ll D[404][404];
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        X[0]=start[0];
        Y[0]=start[1];
        X[1]=target[0];
        Y[1]=target[1];
        int i,x,y;
        int N=specialRoads.size()*2+2;
        FOR(y,N) FOR(x,N) D[y][x]=(y==x)?0:1LL<<60;
        FOR(i,specialRoads.size()) {
			X[i*2+2]=specialRoads[i][0];
			Y[i*2+2]=specialRoads[i][1];
			X[i*2+3]=specialRoads[i][2];
			Y[i*2+3]=specialRoads[i][3];
			D[i*2+2][i*2+3]=specialRoads[i][4];
		}
		FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],abs(X[x]-X[y])+abs(Y[x]-Y[y]));
		FOR(i,N) FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],D[x][i]+D[i][y]);
		return D[0][1];
		
        
    }
};
