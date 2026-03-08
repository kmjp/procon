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
    long long minCost(string s, int encCost, int flatCost) {
		int X=0;
		int L=s.size();
		FORR(c,s) if(c=='1') X++;
		ll ret;
		if(X==0) ret=flatCost;
		else ret=1LL*L*X*encCost;
		
		if(L%2==0) ret=min(ret,minCost(s.substr(0,L/2),encCost,flatCost)+minCost(s.substr(L/2),encCost,flatCost));
		return ret;
        
    }
};

