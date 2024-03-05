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
    vector<int> resultArray(vector<int>& nums) {
		vector<int> A,B;
		A.push_back(nums[0]);
		B.push_back(nums[1]);
		for(int i=2;i<nums.size();i++) {
			if(A.back()>B.back()) A.push_back(nums[i]);
			else B.push_back(nums[i]);
		}
		FORR(b,B) A.push_back(b);
		return A;
        
    }
};
