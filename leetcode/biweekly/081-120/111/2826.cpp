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

int S[101][3];

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
		int N=nums.size();
		int i,j,x;
		int mi=101;
		FOR(i,N+1) for(j=i;j<N+1;j++) {
			int ret=0;
			FOR(x,N) {
				if(x<i) {
					ret+=nums[x]!=1;
				}
				else if(x<j) {
					ret+=nums[x]!=2;
				}
				else {
					ret+=nums[x]!=3;
				}
			}
			mi=min(mi,ret);
		}
		return mi;
        
    }
};
