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
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll ret=1LL<<60;
        vector<ll> cand;
        int i,j;
        for(i=0;i<=101010;i++) cand.push_back(1LL*i*(i+1)/2);
        
        for(j=59;j>=0;j--) {
			ll sum=0;
			FORR(a,workerTimes) {
				ll num=(ret-(1LL<<j))/a;
				sum+=lower_bound(ALL(cand),num+1)-cand.begin()-1;
			}
			if(sum>=mountainHeight) ret-=1LL<<j;
		}
		return ret;
    }
};

