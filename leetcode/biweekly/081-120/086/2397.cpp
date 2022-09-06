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
    int maximumRows(vector<vector<int>>& mat, int cols) {
		int C[12]={};
		int y,x;
		int W=mat[0].size();
		FOR(x,mat[0].size()) FOR(y,mat.size()) C[y]+=mat[y][x];;
		
		int ma=0;
		int mask;
		FOR(mask,1<<W) if(__builtin_popcount(mask)==cols) {
			int ok=0;
			FOR(y,mat.size()) {
				int a=0;
				FOR(x,W) if(mask&(1<<x)) a+=mat[y][x];
				if(C[y]==a) ok++;
			}
			ma=max(ma,ok);
		}
        return ma;
    }
};
