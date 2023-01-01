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
    int distinctPrimeFactors(vector<int>& nums) {
		int C[1010]={};
		FORR(n,nums) C[n]=n;
		
		int ret=0;
		for(int i=2;i<=1000;i++) {
			int is=0;
			for(int j=i;j<=1000;j+=i) if(C[j]) {
				while(C[j]%i==0) {
					C[j]/=i;
					is=1;
				}
			}
			ret+=is;
		}
		return ret;
        
    }
};
