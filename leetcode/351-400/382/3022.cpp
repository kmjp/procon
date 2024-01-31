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
    int minOrAfterOperations(vector<int>& nums, int k) {
		int ret=0;
		int i;
		for(i=29;i>=0;i--) {
			int tmp=ret+(1<<i);
			int cnt=0;
			int la=0;
			FORR(a,nums) {
				int v=a&tmp;
				if(la==0) la=v;
				else la&=v;
				if(la) cnt++;
			}
			
			if(cnt<=k) ret=tmp;
		}
		return ret^((1<<30)-1);
        
    }
};
