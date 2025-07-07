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
    int minMoves(int sx, int sy, int tx, int ty) {
		
		map<pair<int,int>,int> M;
		queue<pair<int,int>> Q;
		M[{tx,ty}]=0;
		Q.push({tx,ty});
		while(Q.size()) {
			tx=Q.front().first;
			ty=Q.front().second;
			Q.pop();
			if(sx==tx&&sy==ty) {
				return M[{tx,ty}];
			}
			if(sx>tx||sy>ty) continue;
			
			if(tx==ty) {
				if(M.count({0,ty})==0) {
					M[{0,ty}]=M[{tx,ty}]+1;
					Q.push({0,ty});
				}
				if(M.count({tx,0})==0) {
					M[{tx,0}]=M[{tx,ty}]+1;
					Q.push({tx,0});
				}
			}
			else if(tx>ty) {
				if(tx%2==0&&tx/2>=ty) {
					M[{tx/2,ty}]=M[{tx,ty}]+1;
					Q.push({tx/2,ty});
				}
				if(tx-ty<=ty) {
					M[{tx-ty,ty}]=M[{tx,ty}]+1;
					Q.push({tx-ty,ty});
				}
			}
			else {
				if(ty%2==0&&ty/2>=tx) {
					M[{tx,ty/2}]=M[{tx,ty}]+1;
					Q.push({tx,ty/2});
				}
				if(ty-tx<=tx) {
					M[{tx,ty-tx}]=M[{tx,ty}]+1;
					Q.push({tx,ty-tx});
				}
			}
		}
		return -1;
        
    }
};
