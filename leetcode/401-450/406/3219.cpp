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
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int H=m,W=n;
        sort(ALL(horizontalCut));
        sort(ALL(verticalCut));
        ll HS=0,WS=0;
        FORR(v,horizontalCut) HS+=v;
        FORR(v,verticalCut) WS+=v;
        ll ret=0;
        FORR(v,horizontalCut) {
			int x=lower_bound(ALL(verticalCut),v)-verticalCut.begin();
			int num=W-x;
			ret+=1LL*num*v;
		}
        FORR(v,verticalCut) {
			int x=lower_bound(ALL(horizontalCut),v+1)-horizontalCut.begin();
			int num=H-x;
			ret+=1LL*num*v;
		}
        
        
		return ret;
    }
};

