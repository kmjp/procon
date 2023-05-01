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

int R[101010],C[101010];

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
		int H=mat.size();
		int W=mat[0].size();
		int y,x,i;
		FOR(y,H) R[y]=0;
		FOR(x,W) C[x]=0;
		vector<int> V(H*W);
		FOR(y,H) FOR(x,W) V[mat[y][x]-1]=y*W+x;
		FOR(i,H*W) {
			int k=V[arr[i]-1];
			R[k/W]++;
			C[k%W]++;
			if(R[k/W]==W) return i;
			if(C[k%W]==H) return i;
		}
        return 0;
    }
};
