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


ll from[2][4];
ll to[2][4];
const ll mo=1000000007;
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
		ZERO(from);
		FORR(n,nums) {
			n%=2;
			int num,mask;
			FOR(num,2) FOR(mask,4) to[num][mask]=from[num][mask];
			
			to[0][n]++;
			(to[1][0+n]+=from[0][0])%=mo;
			(to[1][2+n]+=from[0][1])%=mo;
			FOR(mask,4) {
				if((mask<<1)+n==0) continue;
				if((mask<<1)+n==7) continue;
				(to[1][((mask<<1)+n)%4]+=from[1][mask])%=mo;
			}
			swap(from,to);
		}
		ll ret=from[0][0]+from[0][1]+from[1][0]+from[1][1]+from[1][2]+from[1][3];
		return ret%mo;
        
    }
};

