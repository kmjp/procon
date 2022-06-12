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
    bool strongPasswordCheckerII(string password) {
        if(password.size()<8) return 0;
        int ok=0;
        string S="!@#$%^&*()-+";
        FORR(c,password) {
			if(c>='a'&&c<='z') ok|=1;
			if(c>='A'&&c<='Z') ok|=2;
			if(c>='0'&&c<='9') ok|=4;
			FORR(d,S) if(c==d) ok|=8;
		}
		if(ok!=15) return 0;
		int i;
		FOR(i,password.size()-1) if(password[i]==password[i+1]) return 0;
		return 1;
    }
};


