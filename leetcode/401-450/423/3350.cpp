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

int L[202020],R[202020];

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int N=nums.size();
        L[0]=1;
        int i;
        for(i=1;i<N;i++) L[i]=(nums[i]>nums[i-1])?(L[i-1]+1):1;
        R[N-1]=1;
        for(i=N-2;i>=0;i--) R[i]=(nums[i]<nums[i+1])?(R[i+1]+1):1;
        int ma=0;
        FOR(i,N-1) ma=max(ma,min(L[i],R[i+1]));
        return ma;
    }
};

