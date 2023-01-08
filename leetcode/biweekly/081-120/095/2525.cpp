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
    string categorizeBox(int length, int width, int height, int mass) {
		int x=0;
        if(length>=10000||width>=10000||height>=10000||1LL*length*width*height>=1000000000) x|=1;
        if(mass>=100) x|=2;
        if(x==0) return "Neither";
        if(x==3) return "Both";
        if(x==1) return "Bulky";
        return "Heavy";
        
    }
};

