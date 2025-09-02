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

int ma[1<<20];
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
		int DI=0;
        FORR(n,nums) {
			while(n>=1<<DI) DI++;
		}
        int i,mask;
        FOR(mask,1<<DI) ma[mask]=0;
        FORR(n,nums) ma[n]=n;
        
        FOR(i,DI) FOR(mask,1<<DI) if(mask&(1<<i)) ma[mask]=max(ma[mask],ma[mask^(1<<i)]);
        ll ret=0;
        FORR(n,nums) ret=max(ret,1LL*n*ma[(1<<DI)-1-n]);
        return ret;
    }
};
