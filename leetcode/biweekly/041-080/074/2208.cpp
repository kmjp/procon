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
    int halveArray(vector<int>& nums) {
        multiset<ll> S;
        __int128 sum=0;
        __int128 sum2=0;
        FORR(n,nums) {
			ll a=n;
			a<<=30;
			sum+=a;
			sum2+=a/2;
			S.insert(a);
		}
		int cnt=0;
		while(sum>sum2) {
			ll a=*S.rbegin();
			S.erase(S.find(a));
			sum-=a/2;
			cnt++;
			S.insert(a/2);
		}
		return cnt;
    }
};
