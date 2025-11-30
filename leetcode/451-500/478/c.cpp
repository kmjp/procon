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
    int minMirrorPairDistance(vector<int>& nums) {
		
		map<int,int> M;
		int i,N=nums.size();
		int ret=1<<20;
		
		FOR(i,N) {
			if(M.count(nums[i])) ret=min(ret,i-M[nums[i]]);
			int a=nums[i],v=0;
			while(a) {
				v=v*10+a%10;
				a/=10;
			}
			M[v]=i;
		}
        if(ret>1<<19) ret=-1;
        return ret;
    }
};


