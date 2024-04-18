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
    string findLatestTime(string s) {
		if(s[3]=='?') s[3]='5';
		if(s[4]=='?') s[4]='9';
		if(s[0]=='?'&&s[1]=='?') s[0]=s[1]='1';
		if(s[0]=='?') s[0]='1'-(s[1]>'1');
		if(s[1]=='?') s[1]=(s[0]=='0')?'9':'1';
		return s;
        
    }
};
