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

int F[7][7][7];
int T[7][7][7];

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
		ZERO(F);
		FORR(p,points) {
			F[p[0]][p[1]][p[2]]=1;
		}
		int i;
		FOR(i,100) {
			if(F[target[0]][target[1]][target[2]]) return i;
			int x1,y1,z1;
			int x2,y2,z2;
			ZERO(T);
			FOR(x1,7) FOR(y1,7) FOR(z1,7) if(F[x1][y1][z1]) {
				FOR(x2,7) FOR(y2,7) FOR(z2,7) if(F[x2][y2][z2]&&(x1!=x2||y1!=y2||z1!=z2)) T[(x1+x2)/2][(y1+y2)/2][(z1+z2)/2]=1;
			}
			FOR(x1,7) FOR(y1,7) FOR(z1,7) F[x1][y1][z1]|=T[x1][y1][z1];
			
			
			
		}
		return -1;
		
        
    }
};
