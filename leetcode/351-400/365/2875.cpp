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
    int minSizeSubarray(vector<int>& nums, int target) {
        int N=nums.size();
        ll S=0;
        FORR(a,nums) S+=a;
        ll num=(target/S)*N;
        target%=S;
        
        map<ll,int> X;
        X[0]=0;
        int i;
        ll s=0;
        ll mi=1LL<<60;
        FOR(i,3*N) {
			s+=nums[i%N];
			X[s]=i+1;
			if(X.count(s-target)) {
				mi=min(mi,(ll)i+1-X[s-target]);
			}
		}
        if(mi==1LL<<60) mi=-1;
        else mi+=num;
        return mi;
    }
};
