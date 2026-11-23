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
    long long minCost(vector<int>& nums) {
        vector<pair<int,int>> V;
        FORR(a,nums) {
			if(V.empty()||V.back().first!=a) V.push_back({a,0});
			V.back().second++;
		}
		int N=nums.size();
		ll ret=1LL<<60;
		int i;
		FOR(i,V.size()) {
			if(i==0&&V[i].second==1) continue;
			if(i==V.size()-1&&V[i].second==1) continue;
			ret=min(ret,1LL*V[i].first*(N-V[i].second));
		}
		return ret;
		
    }
};
