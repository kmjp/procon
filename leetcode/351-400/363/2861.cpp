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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
		int ma=0;
		int i,j,x;
		for(i=28;i>=0;i--) {
			int tmp=ma+(1<<i);
			
			FOR(j,k) {
				ll need=0;
				FOR(x,n) if(stock[x]<1LL*composition[j][x]*tmp) need+=(1LL*composition[j][x]*tmp-stock[x])*cost[x];
				if(need<=budget) break;
			}
			
			if(j<k) ma=tmp;
		}
		return ma;
        
    }
};
