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
    bool hasSpecialSubstring(string s, int k) {
		int x,y;
		int N=s.size();
		for(x=0;x+k<=s.size();x++) {
			FOR(y,k-1) if(s[x+y]!=s[x+y+1]) break;
			if(y!=k-1) continue;
			if(x&&s[x-1]==s[x]) continue;
			if(x+k<N&&s[x+k]==s[x+k-1]) continue;
			return 1;
		}
        return 0;
    }
};


