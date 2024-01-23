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
    vector<long long> countOfPairs(int n, int x, int y) {
		vector<ll> V(2*n+3);
		int i;
		if(x>y) swap(x,y);
		x--,y--;
		int d=abs(x-y);
		
		//“à‘¤‚©‚çŠO‘¤
		int t=x;
		FOR(i,n) {
			if(d<=1||abs(i-y)<=abs(i-x)) {
				V[0]+=2;
				V[n-i]-=2;
				continue;
			}
			while(t<y&&(t-i)<=((y-t)+abs(i-x)+1)) t++;
			if(t<=i) {
				V[0]+=2;
				V[n-i]-=2;
				continue;
			}
			V[0]+=2;
			V[t-i]-=2;
			V[abs(i-x)+1]+=2;
			V[abs(i-x)+2]+=2;
			V[abs(i-x)+(y-t)+2]-=2;
			V[abs(i-x)+(n-y)+1]-=2;
		}
		for(i=1;i<V.size();i++) V[i]+=V[i-1];
        V.erase(V.begin());
        V.resize(n);
        return V;
    }
};
