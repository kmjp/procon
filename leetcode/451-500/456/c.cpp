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

int S[255];
bitset<256> vis[256];

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
		int N=nums.size();
		int i,x,y,z;
		FOR(i,N) S[i+1]=S[i]^nums[i];
		int ret=(1<<30)-1;
		for(i=29;i>=0;i--) {
			int tmp=ret-(1<<i);
			FOR(x,256) vis[x].reset();
			vis[0][0]=1;
			FOR(x,N) {
				for(z=x+1;z<=N;z++) if((S[z]^S[x])<=tmp) vis[z] |= vis[x]<<1;
			}
			if(vis[N][k]) ret=tmp;
			
		}
		return ret;
        
    }
};

