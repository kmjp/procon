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
    int minOperations(vector<int>& nums, int target) {
		ll C[51]={};
		int i,j,k;
		FORR(a,nums) {
			FOR(i,31) if(a&(1LL<<i)) C[i]++;
		}
		
		int num=0;
		FOR(i,32) {
			if(target&(1LL<<i)) {
				for(j=i;j<=33;j++) if(C[j]) {
					C[j]--;
					for(k=i;k<j;k++) {
						C[k]++;
						num++;
					}
					break;
				}
				if(j==34) return -1;
			}
			C[i+1]+=C[i]/2;
		}
        return num;
    }
};
