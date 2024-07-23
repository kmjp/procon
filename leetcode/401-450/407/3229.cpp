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
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
		vector<int> V;
		int pre=0;
		int i;
		FOR(i,nums.size()) {
			int x=nums[i]-target[i];
			V.push_back(x-pre);
			pre=x;
		}
		V.push_back(-pre);
		
		ll sum=0;
		FORR(v,V) if(v>0) sum+=v;
		
		
		return sum;
		
        
    }
};


