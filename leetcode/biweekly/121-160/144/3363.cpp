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

ll from[1010],to[1010];

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int N=fruits.size();
        ll ret=0;
        int x,y,loop;
        FOR(x,N) ret+=fruits[x][x];
        FOR(loop,2) {
			FOR(x,N) FOR(y,N) if(x<y) swap(fruits[x][y],fruits[y][x]);
			FOR(x,N) from[x]=-1LL<<60;
			from[N-1]=fruits[0][N-1];
			for(y=1;y<N-1;y++) {
				FOR(x,N) to[x]=-1LL<<60;
				FOR(x,N) if(from[x]>=0) {
					if(x<N-1) to[x+1]=max(to[x+1],from[x]+fruits[y][x+1]);
					to[x-1]=max(to[x-1],from[x]+fruits[y][x-1]);
					to[x]=max(to[x],from[x]+fruits[y][x]);
				}
				swap(from,to);
			}
			cout<<from[N-1]<<endl;
			ret+=from[N-1];
			
		}
        return ret;
    }
};
