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

int X[50],Y[50];

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int N=grid.size();
        int x,y;
        FOR(y,N) FOR(x,N) {
			X[grid[y][x]]=x;
			Y[grid[y][x]]=y;
		}
		int i;
		if(X[0]||Y[0]) return 0;
		FOR(i,N*N-1) {
			int a=abs(X[i]-X[i+1]);
			int b=abs(Y[i]-Y[i+1]);
			if(a+b!=3||abs(a-b)!=1) return 0;
		}
		return 1;
    }
};
