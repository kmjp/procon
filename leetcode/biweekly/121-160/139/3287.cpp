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

int L[402][204][128];
int R[402][204][128];
class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
		int N=nums.size();
		ZERO(L);
		ZERO(R);
		L[0][0][0]=1;
		int i,x,y;
		FOR(i,N) {
			FOR(x,k+1) FOR(y,128) if(L[i][x][y]) {
				L[i+1][x][y]=1;
				L[i+1][x+1][y|nums[i]]=1;
			}
		}
		R[N+1][0][0]=1;
		int ma=0;
		for(i=N-1;i>=0;i--) {
			FOR(x,k+1) FOR(y,128) if(R[i+2][x][y]) {
				R[i+1][x][y]=1;
				R[i+1][x+1][y|nums[i]]=1;
			}
			FOR(x,128) FOR(y,128) if(R[i+1][k][x]&&L[i][k][y]) {
				ma=max(ma,x^y);
			}
		}
        return ma;
    }
};
