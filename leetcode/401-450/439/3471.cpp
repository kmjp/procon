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
    int largestInteger(vector<int>& nums, int k) {
        int C[51]={};
        int N=nums.size(),i,j;
        for(i=0;i+k<=N;i++) {
			set<int> S;
			FOR(j,k) S.insert(nums[i+j]);
			FORR(s,S) C[s]++;
		}
		int ret=-1;
		FOR(i,51) if(C[i]==1) ret=i;
		return ret;
    }
};


