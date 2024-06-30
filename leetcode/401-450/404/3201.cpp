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
    int maximumLength(vector<int>& nums) {
		int ret=0;
		int C[2]={};
		FORR(x,nums) {
			x%=2;
			C[x]++;
		}
		ret=max(C[0],C[1]);
		C[0]=C[1]=0;
		FORR(x,nums) {
			if(x==0) {
				if(C[0]%2==0) C[0]++;
				if(C[1]%2==1) C[1]++;
			}
			else {
				if(C[0]%2==1) C[0]++;
				if(C[1]%2==0) C[1]++;
			}
		}
		ret=max({ret,C[0],C[1]});
        return ret;
    }
};
