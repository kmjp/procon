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
    bool repeatedStringMatch(string a, string b, int x, int y) {
		ll N=a.size();
		ll M=b.size();
		ll LA=N*x;
		ll LB=M*y;
		if(LB>LA) return 0;
		ll pat=min(LB,N+M);
		
		int i,j;
		FOR(i,N) if(i+LB<=LA) {
			int ok=0;
			FOR(j,pat) if(b[j%M]!=a[(i+j)%N]) break;
			if(j==pat) return 1;
		}
		return 0;
			
		
        
    }
};
