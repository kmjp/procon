#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    double separateSquares(vector<vector<int>>& squares) {
		double L=0,R=1e10;
		int i,j;
		FOR(i,100) {
			double M=(L+R)/2;
			double v1=0,v2=0;
			FORR(a,squares) {
				if(a[1]+a[2]<=M) v1+=1LL*a[2]*a[2];
				else if(a[1]>=M) v2+=1LL*a[2]*a[2];
				else {
					v1+=1LL*(M-a[1])*a[2];
					v2+=1LL*(a[1]+a[2]-M)*a[2];
				}
			}
			if(v1<v2) L=M;
			else R=M;
		}
        return L;
    }
};

