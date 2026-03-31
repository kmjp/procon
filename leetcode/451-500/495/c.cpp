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
    int sortableIntegers(vector<int>& nums) {
		ll ret=0;
		int N=nums.size();
		int a,b,x,y;
		for(int i=1;i<=N;i++) if(N%i==0) {
			vector<int> A;
			for(int x=0;x<N;x+=i) {
				int y,z;
				FOR(y,i-1) if(nums[x+y]>nums[x+y+1]) break;
				FOR(z,i) A.push_back(nums[x+(y+1+z)%i]);
			}
			int ok=i;
			FOR(x,N-1) if(A[x]>A[x+1]) ok=0;
			ret+=ok;
		}
		return ret;
        
    }
};
