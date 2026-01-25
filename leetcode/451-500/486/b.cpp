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
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
		set<pair<int,int>> S;
		int i;
		int ret=0;
		vector<pair<int,int>> V;
		FOR(i,costs.size()) {
			V.push_back({costs[i],capacity[i]});
		}
		sort(ALL(V));
		FORR2(a,b,V) {
			if(a<budget) ret=max(ret,b);
			while(S.size()&&S.rbegin()->second+a>=budget) {
				S.erase(*S.rbegin());
			}
			if(S.size()) ret=max(ret,b+S.rbegin()->first);
			S.insert({b,a});
		}
		return ret;
        
    }
};


