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
    int resilientSubarray(vector<int>& nums, int k) {
		int ma=0;
		int ret=0;
		int pre=-1,cnt=0;
		FORR(a,nums) {
			a%=k;
			if(pre!=a) {
				pre=a;
				cnt=0;
			}
			cnt++;
			
			if(a==0) {
				ma=max(ma,cnt);
			}
			else {
				int g=__gcd(k,pre);
				int num=k/g;
				int cand=(cnt-1)/num*num+1;
				ma=max(ma,cand);
			}
			
		}
		return ma;
        
    }
};
