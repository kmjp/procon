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

deque<int> D[202020];

class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
		int N=nums.size();
		int i;
		FOR(i,N) D[nums[i]].push_back(i);
		
		vector<int> ret;
		int cur=0;
		while(cur<N) {
			int mex=0;
			int tar=cur;
			while(D[mex].size()) tar=max(tar,D[mex++][0]);
			for(i=cur;i<=tar;i++) D[nums[i]].pop_front();
			cur=tar+1;
			ret.push_back(mex);
		}
		
		
        
        return ret;
    }
};

