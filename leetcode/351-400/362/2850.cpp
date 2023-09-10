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
    int minimumMoves(vector<vector<int>>& grid) {
		int y,x,i,y2,x2;
		vector<pair<int,int>> V;
		FOR(y,3) FOR(x,3) {
			FOR(i,grid[y][x]) V.push_back({y,x});
		}
		sort(ALL(V));
		int mi=3030;
		do {
			int sum=0;
			FOR(y,3) FOR(x,3) {
				int y2=V[y*3+x].first;
				int x2=V[y*3+x].second;
				sum+=abs(y2-y)+abs(x2-x);
			}
			mi=min(mi,sum);
			
			
		} while(next_permutation(ALL(V)));
		return mi;
        
    }
};
