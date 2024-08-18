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


int ng[202020];

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
		int N=nums.size();
		int i;
		for(i=1;i<N;i++) {
			ng[i]=ng[i-1];
			if(nums[i]==nums[i-1]+1) {
				;
			}
			else {
				ng[i]++;
			}
		}
		
		vector<int> ret;
		for(i=0;i+k<=N;i++) {
			if(ng[i+k-1]-ng[i]==0) {
				ret.push_back(nums[i+k-1]);
			}
			else {
				ret.push_back(-1);
			}
		}
		return ret;
		
        
    }
};
