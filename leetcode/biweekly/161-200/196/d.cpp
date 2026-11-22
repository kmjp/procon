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

int S[20][101010];
int ng[1<<18];

class Solution {
public:
    int minSetBits(vector<int>& nums, int k) {
		int i,j,N=nums.size();
		FOR(i,20) {
			FOR(j,N) {
				S[i][j+1]=S[i][j];
				if(nums[j]&(1<<i)) S[i][j+1]++;
			}
		}
		ZERO(ng);
		for(j=0;j+k<=N;j++) {
			int v=0;
			FOR(i,20) if(S[i][j+k]-S[i][j]==k) v|=1<<i;
			ng[v^((1<<18)-1)]=1;
		}
		int mask;
		FOR(i,18) FOR(mask,1<<18) if((mask&(1<<i))&&ng[mask]) ng[mask^(1<<i)]=1;
		int ret=101;
		FOR(mask,1<<18) if(ng[mask]==0) ret=min(ret,__builtin_popcount(mask));
		if(ret>100) ret=-1;
		return ret;
		
        
    }
};

