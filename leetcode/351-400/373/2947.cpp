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
    int beautifulSubstrings(string s, int k) {
		FORR(c,s) {
			if(c=='a'||c=='e'||c=='i'||c=='u'||c=='o') c=0;
			else c=1;
		}
		int ret=0;
		int y,x;
		FOR(x,s.size()) {
			int C[2]={};
			for(y=x;y<s.size();y++) {
				C[s[y]]++;
				if(C[0]==C[1]&&C[0]*C[1]%k==0) ret++;
			}
		}
		return ret;
        
    }
};
