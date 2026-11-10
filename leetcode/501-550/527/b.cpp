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

int ok[101010];

class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
		int N=nums.size();
		ok[N-1]=1;
		int i;
		vector<int> A=nums,B=target;
		sort(ALL(A));
		sort(ALL(B));
		if(A!=B) return 0;
		
		for(i=N-2;i>=0;i--) {
			ok[i]=ok[i+1]&(target[i]>=target[i+1]);
		}
		int ret=0;
		FOR(i,N) {
			if(ok[i]) ret++;
			if(nums[i]!=target[i]) break;
		}
		return ret;
        
    }
};
