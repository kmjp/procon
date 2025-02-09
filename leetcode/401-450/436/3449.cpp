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
    long long maxScore(vector<int>& points, int m) {
        ll ret=0;
        int N=points.size();
        int i,j;
        for(int j=50;j>=0;j--) {
			ll tmp=ret+(1LL<<j);
			
			ll sum=0;
			ll nex=0;
			ll add=0;
			FOR(i,N) if(sum<=m) {
				ll need=(tmp+points[i]-1)/points[i];
				if(nex>=need) {
					nex=0;
					add++;
				}
				else {
					need=(tmp-nex*points[i]+points[i]-1)/points[i];
					sum+=2*need-1+add;
					nex=max(need-1,0LL);
					add=0;
				}
			}
			if(sum<=m) ret=tmp;
			
			
		}
		return ret;
    }
};


