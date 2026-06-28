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
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
		sort(ALL(occupiedIntervals));
		vector<pair<int,int>> V;
		vector<vector<int>> W;
		FORR(a,occupiedIntervals) {
			a[1]++;
			if(V.size()&&a[0]<=V.back().second) V.back().second=max(V.back().second,a[1]);
			else V.push_back({a[0],a[1]});
		}
		freeEnd++;
		FORR2(a,b,V) {
			if(b<=freeStart||a>=freeEnd) {
				W.push_back({a,b-1});
			}
			else {
				if(a<freeStart) {
					W.push_back({a,freeStart-1});
				}
				if(freeEnd<b) {
					W.push_back({freeEnd,b-1});
				}
			}
		}
		return W;
        
    }
};
