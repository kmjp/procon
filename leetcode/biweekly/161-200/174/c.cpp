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

class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
		
		map<int,ll> M[2];
		M[0][0]=1;
		int cur=0;
		ll ret=0;
		FORR(a,nums) {
			cur^=a;
			ll x=M[0][cur^target1];
			ll y=M[1][cur^target2];
			ret=(x+y)%mo;
			(M[1][cur]+=x)%=mo;
			(M[0][cur]+=y)%=mo;
		}
		return ret;
        
    }
};


