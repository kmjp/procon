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

ll S[202020];

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int N=nums.size();
        int i;
        FOR(i,2*N) S[i+1]=S[i]+nums[i%N];
        
        ll ret=0;
        FOR(i,N) if(S[N/2+i]-S[i]>S[N+i]-S[N/2+i]) ret++;
        return ret;
        
    }
};
