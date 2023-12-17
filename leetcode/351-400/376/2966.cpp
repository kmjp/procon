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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
		sort(ALL(nums));
		int N=nums.size()/3;
		vector<vector<int>> V;
		int i;
		FOR(i,N) {
			if(nums[i*3]+k<nums[i*3+2]) return {};
			V.push_back({nums[3*i],nums[3*i+1],nums[3*i+2]});
		}
		return V;
        
    }
};
