#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
		int i;
		vector<pair<int,int>> V[2];
		FORR(a,rectangles) {
			V[0].push_back({a[0],a[2]});
			V[1].push_back({a[1],a[3]});
		}
		FOR(i,2) {
			sort(ALL(V[i]));
			vector<pair<int,int>> E;
			FORR(v,V[i]) {
				if(E.size()&&E.back().second>v.first) {
					E.back().second=max(E.back().second,v.second);
				}
				else {
					E.push_back(v);
				}
			}
			if(E.size()>=3) return 1;
			
		}
        return 0;
    }
};
