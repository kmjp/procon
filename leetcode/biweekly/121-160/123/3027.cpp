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
    int numberOfPairs(vector<vector<int>>& points) {
		FORR(a,points) {
			swap(a[0],a[1]);
			a[0]=-a[0];
		}
		sort(ALL(points));
		FORR(a,points) a[0]=-a[0];
		int a,b;
		int ret=0;
		FOR(b,points.size()) {
			int ma=1<<30;
			set<int> S;
			for(a=b-1;a>=0;a--) {
				if(points[a][1]>points[b][1]) continue;
				if(S.lower_bound(points[a][1])==S.end()) ret++;
				S.insert(points[a][1]);
			}
		}
        return ret;
    }
};
