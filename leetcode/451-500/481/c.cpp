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
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
		int i,n=nums.size();
		map<int,int> NC,FC,NG;
		int ng=0,ma=0;
		FOR(i,n) {
			if(nums[i]==forbidden[i]) {
				ng++;
				ma=max(ma,++NG[nums[i]]);
			}
			NC[nums[i]]++;
			FC[forbidden[i]]++;
		}
		FORR2(a,b,NC) if(b>n-FC[a]) return -1;
		return max(ma,(ng+1)/2);
        
    }
};
