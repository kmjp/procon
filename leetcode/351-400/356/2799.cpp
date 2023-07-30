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

int ret[2030];

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
		MINUS(ret);
		int num=0;
		
		int x,y;
		FOR(x,nums.size()) {
			if(ret[nums[x]]==-1) num++;
			ret[nums[x]]=0;
		}
		MINUS(ret);
		int a=0;
		
		
		FOR(x,nums.size()) {
			int anum=0;
			for(y=x;y<nums.size();y++) {
				if(ret[nums[y]]!=x) {
					anum++;
				}
				ret[nums[y]]=x;
				if(anum==num) a++;
			}
		}
        return a;
    }
};
