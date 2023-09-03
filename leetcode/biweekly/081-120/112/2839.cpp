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
    bool canBeEqual(string s1, string s2) {
		if(s1[0]>s1[2]) swap(s1[0],s1[2]);
		if(s2[0]>s2[2]) swap(s2[0],s2[2]);
		if(s1[1]>s1[3]) swap(s1[1],s1[3]);
		if(s2[1]>s2[3]) swap(s2[1],s2[3]);
        return s1==s2;
    }
};
