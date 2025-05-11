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

bitset<1024> from[303];
bitset<1024> to[303];

class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        ZERO(from);
        int i;
        FOR(i,n) from[i][0]=1;
        while(k--) {
			ZERO(to);
			FORR(e,edges) {
				to[e[1]]|=from[e[0]]<<e[2];
			}
			swap(from,to);
		}
		int ret=-1;
		int j;
		FOR(i,n) FOR(j,t) if(from[i][j]) ret=max(ret,j);
		return ret;
		
    }
};

