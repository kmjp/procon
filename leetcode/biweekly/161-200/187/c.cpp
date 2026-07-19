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
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
		int C[3]={};
		ll ret=0;
		FORR(x,nums) {
			if(x<a) x=0;
			else if(x>=a&&x<=b) x=1;
			else x=2;
			if(x==0) ret+=C[1]+C[2];
			if(x==1) ret+=C[2];
			C[x]++;
		}
		return ret%1000000007;
        
    }
};
