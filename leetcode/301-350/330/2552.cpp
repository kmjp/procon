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

int L[4040][4040],R[4040][4040];

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
		int N=nums.size();
		int x,y;
		FOR(y,N) {
			int num=0;
			FOR(x,y) {
				if(nums[x]<nums[y]) num++;
				L[y][x]=num;
			}
			num=0;
			for(x=N-1;x>y;x--) {
				if(nums[y]<nums[x]) num++;
				R[y][x]=num;
			}
		}
		
		ll ret=0;
		FOR(y,N) {
			FOR(x,y) if(nums[x]>nums[y]) {
				ll a=x?L[y][x-1]:0;
				ll b=(y<N-1)?R[x][y+1]:0;
				ret+=a*b;
			}
		}
		return ret;
		
        
    }
};
