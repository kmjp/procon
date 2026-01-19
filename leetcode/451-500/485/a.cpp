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
    int vowelConsonantScore(string s) {
		int a=0,b=0;
		FORR(c,s) {
			if(c=='a') a++;
			else if(c=='i') a++;
			else if(c=='u') a++;
			else if(c=='e') a++;
			else if(c=='o') a++;
			else if(c>='a'&&c<='z') b++;
		}
        if(b) return a/b;
        return 0;
    }
};


