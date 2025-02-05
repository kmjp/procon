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


ll from[16],to[16];

class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int N=target.size();
        int i,mask;
        FOR(mask,1<<N) from[mask]=1LL<<60;
        from[0]=0;
        FORR(n,nums) {
			int mask2;
			FOR(mask2,1<<N) to[mask2]=from[mask2];
			FOR(mask2,1<<N) if(mask2) {
				ll a=1;
				FOR(i,N) if(mask2&(1<<i)) a=a*target[i]/__gcd(a,(ll)target[i]);
				ll add=(a-n%a)%a;
				FOR(mask,1<<N) to[mask|mask2]=min(to[mask|mask2],from[mask]+add);
			}
			swap(from,to);
		}
        return from[(1<<N)-1];
        
        
        
    }
};


