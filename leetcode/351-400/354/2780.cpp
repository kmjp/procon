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
    int minimumIndex(vector<int>& nums) {
		map<int,int> A,B;
		set<pair<int,int>> L,R;
		FORR(n,nums) {
			R.erase({B[n],n});
			B[n]++;
			R.insert({B[n],n});
		}
		int i;
		FOR(i,nums.size()-1) {
			int x=nums[i];
			L.erase({A[x],x});
			A[x]++;
			L.insert({A[x],x});
			R.erase({B[x],x});
			B[x]--;
			R.insert({B[x],x});
			
			int LV=-1;
			int RV=-2;
			if(R.rbegin()->first*2>nums.size()-(i+1)) RV=R.rbegin()->second;
			if(L.rbegin()->first*2>i+1) LV=L.rbegin()->second;
			if(LV==RV) return i;
			
		}
        return -1;
    }
};
