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
    long long maxSpending(vector<vector<int>>& values) {
		int H=values.size();
		int W=values[0].size();
		vector<int> V(H,W-1);
		set<pair<int,int>> S;
		int x,y;
		FOR(y,H) S.insert({values[y][W-1],y});
		ll ret=0;
		ll step=1;
		while(S.size()) {
			y=S.begin()->second;
			S.erase(S.begin());
			ret+=step*values[y][V[y]];
			V[y]--;
			if(V[y]>=0) S.insert({values[y][V[y]],y});
			step++;
		}
		return ret;
        
    }
};
