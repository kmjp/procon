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
    string concatHex36(int n) {
        int a=n*n;
        int b=n*n*n;
        string A,B;
        string V="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        while(a) {
			A+=V[a%16];
			a/=16;
		}
        while(b) {
			B+=V[b%36];
			b/=36;
		}
		reverse(ALL(A));
		reverse(ALL(B));
		return A+B;
    }
};
