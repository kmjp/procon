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
    int maximumSum(vector<int>& nums) {
		vector<int> C[3];
		ll sum=0;
		FORR(a,nums) {
			C[a%3].push_back(a);
		}
		int i;
		FOR(i,3) {
			sort(ALL(C[i]));
			reverse(ALL(C[i]));
		}
		ll ret=0;
		int a,b,c;
		FOR(a,4) FOR(b,4) FOR(c,4) if(a+b+c==3&&a<=C[0].size()&&b<=C[1].size()&&c<=C[2].size()) {
			ll csum=0;
			FOR(i,a) csum+=C[0][i];
			FOR(i,b) csum+=C[1][i];
			FOR(i,c) csum+=C[2][i];
			if(csum%3==0) ret=max(ret,csum);
			
		}
        return ret;
    }
};

