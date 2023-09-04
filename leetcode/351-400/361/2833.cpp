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
    int countSymmetricIntegers(int low, int high) {
		int i;
		int ret=0;
		for(i=low;i<=high;i++) {
			if(i>=10&&i<100) {
				if(i%10==i/10) ret++;
			}
			if(i>=1000&&i<10000) {
				int x=i/1000+i/100%10;
				int y=i/10%10+i%10;
				if(x==y) ret++;
			}
		}
		
		return ret;
		
		
		
        
    }
};
