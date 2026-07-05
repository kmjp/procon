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
	int dig(int v) {
		int mi=9,ma=0;
		while(v) {
			mi=min(mi,v%10);
			ma=max(ma,v%10);
			v/=10;
		}
		return ma-mi;
	}
    int maxDigitRange(vector<int>& nums) {
		int ma=0;
		FORR(a,nums) ma=max(ma,dig(a));
		int ret=0;
		FORR(a,nums) if(dig(a)==ma) ret+=a;
		return ret;
        
    }
};


