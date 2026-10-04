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


ll F[2][2];
ll T[2][2];

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int x,y,i;
        ll ma=-1LL<<60;
        FOR(x,2) FOR(y,2) F[x][y]=-1LL<<60;
        FORR(v,nums) {
			FOR(x,2) FOR(y,2) T[x][y]=-1LL<<60;
			
			T[0][0]=max(F[1][0],0LL)+v;
			T[1][0]=F[0][0]-v;
			T[0][1]=max(F[1][1]+v,F[0][0]);
			T[1][1]=max(F[0][1]-v,F[1][0]);
			
			FOR(x,2) FOR(y,2) {
				F[x][y]=T[x][y];
				ma=max(ma,F[x][y]);
			}
		}
		return ma;
        
        
    }
};
