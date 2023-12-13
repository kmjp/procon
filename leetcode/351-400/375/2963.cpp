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

const ll mo=1000000007;


class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
		int N=nums.size();
		int i;
		map<int,int> L,R;
		FOR(i,N) {
			if(L.count(nums[i])==0) L[nums[i]]=i;
			R[nums[i]]=i;
		}
		
		ZERO(NG);
		ll ret=1;
		int ng=0;
		FOR(i,N-1) {
			if(L[nums[i]]==i) ng++;
			if(R[nums[i]]==i) ng--;
			if(ng==0) ret=ret*2%mo;
		}
		
		
		return ret;
        
    }
};
