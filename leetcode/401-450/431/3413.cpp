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
    long long maximumCoins(vector<vector<int>>& coins, int k) {
		ll ret=0;
		sort(ALL(coins));
		vector<pair<ll,ll>> V;
		int pre=-1<<30;
		FORR(a,coins) {
			a[1]++;
			V.push_back({a[0]-pre,0});
			V.push_back({a[1]-a[0],a[2]});
			pre=a[1];
		}
		V.push_back({1<<30,0});
		int i;
		FOR(i,2) {
			ll num=0,sum=0;
			for(int L=0,R=0;L<V.size()-1;L++) {
				if(L>R) {
					num=sum=0;
					R=L;
				}
				while(num+V[R].first<=k) {
					num+=V[R].first;
					sum+=V[R].first*V[R].second;
					R++;
				}
				ret=max(ret,sum+(k-num)*V[R].second);
				num-=V[L].first;
				sum-=V[L].first*V[L].second;

			}
			reverse(ALL(V));
		}
		
		
		return ret;
        
    }
};


