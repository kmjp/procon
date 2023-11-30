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
    bool areSimilar(vector<vector<int>>& mat, int k) {
		int H=mat.size(),W=mat[0].size();
		int y,x;
		for(y=0;y<H;y+=2) {
			FOR(x,W) if(mat[y][x]!=mat[y][(x+W-k%W)%W]) return 0;
		}
		for(y=1;y<H;y+=2) {
			FOR(x,W) if(mat[y][x]!=mat[y][(x+k)%W]) return 0;
		}
        return 1;
    }
};
