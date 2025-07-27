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
    long long maximizeXorAndXor(vector<int>& nums) {
		ll ma=0;
		int i,mask,N=nums.size();
		vector<int> cand;
		FOR(mask,1<<N) {
			int sumand=(1<<30)-1;
			int txor=0;
			FOR(i,N) {
				if(mask&(1<<i)) sumand&=nums[i];
				else txor^=nums[i];
			}
			if(mask==0) sumand=0;
			int max_xor=0;
			cand.clear();
			FOR(i,N) if((mask&(1<<i))==0) {
				int v=nums[i]&(~txor);
				FORR(a,cand) v=min(v,a^v);
				if(v) {
					cand.push_back(v);
					max_xor=max(max_xor,max_xor^v);
				}
			}
			ma=max(ma,sumand+txor+2LL*max_xor);
		}
		return ma;
        
    }
};


