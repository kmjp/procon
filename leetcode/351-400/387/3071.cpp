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
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
		int N=grid.size();
		int C[2][3]={};
		int y,x;
		FOR(y,N) FOR(x,N) {
			if(y<N/2) {
				C[(x==y)||(N-1-x)==y][grid[y][x]]++;
			}
			else {
				C[x==N/2][grid[y][x]]++;
			}
		}
		int mi=5050;
		mi=min(mi,C[0][0]+C[0][1]+C[1][0]+C[1][2]);
		mi=min(mi,C[0][0]+C[0][1]+C[1][1]+C[1][2]);
		mi=min(mi,C[0][1]+C[0][2]+C[1][0]+C[1][1]);
		mi=min(mi,C[0][1]+C[0][2]+C[1][0]+C[1][2]);
		mi=min(mi,C[0][0]+C[0][2]+C[1][0]+C[1][1]);
		mi=min(mi,C[0][0]+C[0][2]+C[1][2]+C[1][1]);
		return mi;
        
    }
};
