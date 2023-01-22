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
    bool isReachable(int X, int Y) {
        while(X!=Y) {
			while(X%2==0) X/=2;
			while(Y%2==0) Y/=2;
			if(X<Y) swap(X,Y);
			X%=Y;
			if(X==0) {
				return Y==1;
			}
		}
		while(X%2==0) X/=2;
		while(Y%2==0) Y/=2;
		return X==1;
    }
};
