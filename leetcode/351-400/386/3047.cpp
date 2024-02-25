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
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
		int ret=0;
		int a,b,N=bottomLeft.size();
		FOR(a,N) FOR(b,a) {
			int x=min(topRight[a][0],topRight[b][0])-max(bottomLeft[a][0],bottomLeft[b][0]);
			int y=min(topRight[a][1],topRight[b][1])-max(bottomLeft[a][1],bottomLeft[b][1]);
			ret=max(ret,min(x,y));
		}
		return 1LL*ret*ret;
        
    }
};
