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
    long long maxArea(vector<vector<int>>& coords) {
        ll ma=-1;
        int i;
        FOR(i,2) {
			FORR(a,coords) swap(a[0],a[1]);
	        sort(ALL(coords));
	        ll mix=coords[0][0];
	        ll mx=coords.back()[0];
	        map<int,int> V;
	        FORR(a,coords) {
				if(V.count(a[0])) {
					if(a[0]<mx) ma=max(ma,1LL*(a[1]-V[a[0]])*(mx-a[0]));
					if(a[0]>mix) ma=max(ma,1LL*(a[1]-V[a[0]])*(a[0]-mix));
				}
				else {
					V[a[0]]=a[1];
				}
			}
	    }
	    return ma;
    }
};
