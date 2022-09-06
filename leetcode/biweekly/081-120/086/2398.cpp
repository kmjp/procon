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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
		int ma=0;
		int N=chargeTimes.size();
		multiset<ll> S={0};
		ll sum=0;
		for(int L=0,R=0;L<N;L++) {
			if(R<L) {
				R=L;
				S={0};
				sum=0;
			}
			while(R<N) {
				ll a=max(*S.rbegin(),(ll)chargeTimes[R]);
				ll b=(R+1-L)*(sum+runningCosts[R]);
				if(a+b>budget) break;
				S.insert(chargeTimes[R]);
				sum+=runningCosts[R];
				R++;
			}
			ma=max(ma,R-L);
			if(R>L) {
				S.erase(S.find(chargeTimes[L]));
				sum-=runningCosts[L];
			}
		}
        return ma;
    }
};
