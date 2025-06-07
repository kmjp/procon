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



ll from[2020];
ll to[2020];

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
		ZERO(from);
		ZERO(to);
		int i,j,N=prices.size();
		FOR(i,k) {
			ll a=0,b=-(1LL<<60),c=-(1LL<<60);
			FOR(j,N) {
				int v=prices[j];
				to[j]=max(to[j],b+v);
				to[j]=max(to[j],c-v);
				if(j) to[j]=max(to[j],to[j-1]);
				b=max(b,a-v);
				c=max(c,a+v);
				a=max(a,from[j]);
			}
			
			
			FOR(j,N+1) from[j]=to[j];
		}
		return from[N-1];
        
    }
};

