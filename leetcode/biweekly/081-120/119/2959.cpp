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

int E[10][10],R[10][10];
int id[10];
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int x,y,z;
        FOR(x,n) FOR(y,n) E[x][y]=(x==y)?0:1<<20;
		FORR(r,roads) {
			chmin(E[r[0]][r[1]],r[2]);
			chmin(E[r[1]][r[0]],r[2]);
		}
        int ret=0;
        int mask=0;
        FOR(mask,1<<n) {
			int nu=0;
			vector<int> V;
			FOR(x,n) if(mask&(1<<x)) {
				nu++;
				V.push_back(x);
			}
			FOR(x,nu) FOR(y,nu) R[x][y]=E[V[x]][V[y]];
			FOR(z,nu) FOR(x,nu) FOR(y,nu) R[x][y]=min(R[x][y],R[x][z]+R[z][y]);
			int ok=1;
			FOR(x,nu) FOR(y,nu) if(R[x][y]>maxDistance) ok=0;
			ret+=ok;
			
			
			
		}
        return ret;
    }
};
