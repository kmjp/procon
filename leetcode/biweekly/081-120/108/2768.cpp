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
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
		vector<ll> R={1LL*(m-1)*(n-1),0,0,0,0};
		set<pair<int,int>> S;
		set<pair<int,int>> C;
		FORR(a,coordinates) {
			S.insert({a[0],a[1]});
			if(a[0]&&a[1]) C.insert({a[0]-1,a[1]-1});
			if(a[0]&&a[1]+1<n) C.insert({a[0]-1,a[1]});
			if(a[0]+1<m&&a[1]) C.insert({a[0],a[1]-1});
			if(a[0]+1<m&&a[1]+1<n) C.insert({a[0],a[1]});
		}
		FORR(a,C) {
			int x=0;
			R[x]--;
			if(S.count({a.first,a.second})) x++;
			if(S.count({a.first,a.second+1})) x++;
			if(S.count({a.first+1,a.second})) x++;
			if(S.count({a.first+1,a.second+1})) x++;
			R[x]++;
		}
        return R;
    }
};
