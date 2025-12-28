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
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
		costBoth=min(costBoth,cost1+cost2);
		ll ret=1LL*min(need1,need2)*costBoth;
		if(need1>need2) ret+=1LL*min(cost1,costBoth)*(need1-need2);
		if(need1<need2) ret+=1LL*min(cost2,costBoth)*(need2-need1);
		return ret;
        
    }
};

