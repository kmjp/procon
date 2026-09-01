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
    int countSpecialIntegers(vector<int>& nums) {
		int L[101]={},R[101]={},num[101]={};
		int i,N=nums.size();
		FOR(i,101) L[i]=1010,R[i]=-1;
		FOR(i,N) {
			int x=nums[i];
			L[x]=min(L[x],i);
			R[x]=i;
			num[x]++;
		}
		int ret=0;
		FOR(i,101) if(num[i]) {
			if(R[i]-L[i]==num[i]-1) ret++;
		}
		return ret;
        
    }
};
