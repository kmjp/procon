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
    int mirrorFrequency(string s) {
		int C[256]={};
		FORR(c,s) C[c]++;
		int ret=0;
		int i;
		for(i='a';i<'z';i++) {
			int j='z'-(i-'a');
			if(i<j) ret+=abs(C[i]-C[j]);
		}
		for(i='0';i<'9';i++) {
			int j='9'-(i-'0');
			if(i<j) ret+=abs(C[i]-C[j]);
		}
		return ret;
        
    }
};
