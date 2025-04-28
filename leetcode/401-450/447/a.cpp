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

set<int> Ys[101010];
set<int> Xs[101010];

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        FORR(a,buildings) {
			Xs[a[0]].insert(a[1]);
			Ys[a[1]].insert(a[0]);
		}
        int ret=0;
        FORR(a,buildings) {
			auto it=Xs[a[0]].lower_bound(a[1]);
			if(it==Xs[a[0]].begin()||next(it)==Xs[a[0]].end()) continue;
			it=Ys[a[1]].lower_bound(a[0]);
			if(it==Ys[a[1]].begin()||next(it)==Ys[a[1]].end()) continue;
			ret++;
		}
        FORR(a,buildings) {
			Xs[a[0]].clear();
			Ys[a[1]].clear();
		}
		return ret;
    }
};


