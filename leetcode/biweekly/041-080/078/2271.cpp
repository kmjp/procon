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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
		ll ma=0;
		sort(ALL(tiles));
		int i;
		FOR(i,2) {
			ll sum=0;
			for(int L=0,R=0;L<tiles.size();L++) {
				while(R<tiles.size()&&tiles[R][1]<=tiles[L][0]+carpetLen-1) {
					sum+=tiles[R][1]-tiles[R][0]+1;
					R++;
				}
				
				ll add=0;
				if(R<tiles.size()) add=max(0,tiles[L][0]+carpetLen-tiles[R][0]);
				ma=max(ma,sum+add);
				
				sum-=tiles[L][1]-tiles[L][0]+1;
			}
			reverse(ALL(tiles));
			FORR(v,tiles) {
				v[0]=(1<<30)-v[0];
				v[1]=(1<<30)-v[1];
			}
		}
        return ma;
    }
};
