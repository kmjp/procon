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
const ll mo=1000000007;


class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int i,j;
        ZERO(from);
        FOR(i,nums[0]+1) from[i]=1;
        
        for(i=1;i<nums.size();i++) {
			int n=nums[i];
			int p=nums[i-1];
			FOR(j,1020) if(j) (from[j]+=from[j-1])%=mo;
			ZERO(to);
			FOR(j,n+1) {
				int x=(n>=p)?j-(n-p):j;
				if(x>=0) to[j]=from[x];
			}
			swap(from,to);
		}
		ll ret=0;
		FOR(i,1010) ret+=from[i];
		return ret%mo;
        
    }
};
