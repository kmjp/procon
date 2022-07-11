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


ll S[101010];
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
		ll a=k1+k2;
		int i;
		ZERO(S);
		FOR(i,nums1.size()) S[abs(nums1[i]-nums2[i])]++;
		
		ll ret=0;
		for(i=100000;i>0;i--) {
			ll b=min(a,S[i]);
			a-=b;
			S[i]-=b;
			S[i-1]+=b;
			ret+=S[i]*i*i;
		}
		return ret;
		
		
        
    }
};
