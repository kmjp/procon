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
    int maxDistance(string s, int k) {
		int X[2]={},Y[2]={};
		
		int ma=0;
		
		FORR(c,s) {
			if(c=='N') Y[0]++;
			if(c=='S') Y[1]++;
			if(c=='E') X[0]++;
			if(c=='W') X[1]++;
			
			int xa=X[0],xb=X[1];
			int ya=Y[0],yb=Y[1];
	        if(xa<xb) swap(xa,xb);
	        if(ya<yb) swap(ya,yb);
	        int nk=k;
	        int a=min(yb,nk);
	        nk-=a;
	        ya+=a;
	        yb-=a;
	        
	        a=min(xb,nk);
	        nk-=a;
	        xa+=a;
	        xb-=a;
			ma=max(ma,xa+ya-xb-yb);
			
        }
        
        
        return ma;
    }
};


