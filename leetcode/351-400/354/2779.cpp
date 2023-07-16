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

int sum[101010];
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
		int ma=0;
		ZERO(sum);
		FORR(a,nums) {
			sum[max(0,a-k)]++;
			sum[min(100000,a+k+1)]--;
		}
		int i;
		FOR(i,100001) {
			if(i) sum[i]+=sum[i-1];
			ma=max(ma,sum[i]);
		}
		return ma;
		
        
    }
};
