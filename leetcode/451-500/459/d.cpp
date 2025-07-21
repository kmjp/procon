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
    int countTrapezoids(vector<vector<int>>& points) {
		map<array<int,2>,ll> S;
		map<array<int,3>,ll> L,M;
		map<array<int,5>,ll> ML;
		
		FORR(a,points) FORR(b,points) if(a<b) {
			int dx=b[0]-a[0],dy=b[1]-a[1];
			int g=__gcd(abs(dx),abs(dy));
			dx/=g;
			dy/=g;
			if(dx<0||dx==0&&dy<0) {
				dx=-dx,dy=-dy;
			}
			int cross=dx*a[1]-dy*a[0];
			S[{dx,dy}]++;
			L[{dx,dy,cross}]++;
			M[{a[0]+b[0],a[1]+b[1]}]++;
			ML[{a[0]+b[0],a[1]+b[1],dx,dy,cross}]++;
		}
		ll ret=0;
		FORR2(a,b,S) ret+=b*(b-1)/2;
		FORR2(a,b,L) ret-=b*(b-1)/2;
		FORR2(a,b,M) ret-=b*(b-1)/2;
		FORR2(a,b,ML) ret+=b*(b-1)/2;
        return ret;
    }
};


