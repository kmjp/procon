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

const ll mo=1000000007;

ll from[2010];
ll to[2010];


class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
		ZERO(from);
		int i;
		ll sum=0;
		from[0]=1;
		FORR(n,nums) {
			ZERO(to);
			FOR(i,k+1) {
				ll sm=sum-i;
				if(sm<0) continue;
				(to[min((ll)k,min((ll)i+n,sm))]+=from[i])%=mo;
				(to[min((ll)k,min((ll)i,sm+n))]+=from[i])%=mo;
				
			}
			sum+=n;
			swap(from,to);
		}
		return from[k];
        
    }
};
