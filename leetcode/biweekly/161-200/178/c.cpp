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
    int minCost(vector<int>& nums1, vector<int>& nums2) {
		map<int,int> A;
		FORR(a,nums1) A[a]++;
		FORR(a,nums2) A[a]--;
		int ret=0;
		FORR2(a,b,A) {
			if(b%2) return -1;
			if(b>0) ret+=b/2;
		}
		return ret;
        
    }
};


