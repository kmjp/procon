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
    long long maximumSubsequenceCount(string text, string pattern) {
		string a=pattern[0]+text;
		string b=text+pattern[1];
		
		ll ret=0;
		ll x=0;
		FORR(c,a) {
			if(c==pattern[1]) ret+=x;
			if(c==pattern[0]) x++;
		}
		ll ret2=0;
		x=0;
		FORR(c,b) {
			if(c==pattern[1]) ret2+=x;
			if(c==pattern[0]) x++;
		}
		return max(ret,ret2);
        
    }
};