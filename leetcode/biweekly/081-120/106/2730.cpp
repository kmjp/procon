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
    int longestSemiRepetitiveSubstring(string s) {
		int ma=0;
		int i,j;
		FOR(i,s.size()) {
			int ng=0;
			for(j=1;i+j<=s.size();j++) {
				if(j>=2&&s[i+j-1]==s[i+j-2]) ng++;
				if(ng<=1) ma=max(ma,j);
			}
		}
		return ma;
        
    }
};

