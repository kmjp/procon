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
    bool isStrictlyPalindromic(int n) {
        int i;
        for(i=2;i<=n;i++) {
			if(i*i>n) break;
			vector<int> S,T;
			int x=i;
			while(x) {
				S.push_back(x%i);
				x/=i;
			}
			T=S;
			reverse(ALL(T));
			if(S!=T) return 0;
		}
		return 1;
    }
};
