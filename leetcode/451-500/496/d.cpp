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


int P[5050];

int cost[5050][5050][2][2];

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int N=nums.size();
        
		int x,y,i,j;
        FOR(i,N) {
			ll a=nums[i];
			ll b=nums[(i+1)%N];
			ll c=nums[(i+N-1)%N];
			if(a>max(b,c)) P[i]=0;
			else P[i]=max(b,c)+1-a;
		}
		
		FOR(x,N+1) FOR(y,N+1) FOR(i,2) FOR(j,2) {
			cost[x][y][i][j]=1LL<<30;
		}
		cost[0][0][0][0]=0;
		cost[0][1][1][1]=P[0];
		for(i=1;i<N;i++) {
			FOR(x,2) FOR(y,2) FOR(j,N+1) {
				// take
				if(y==0) cost[i][j+1][x][1]=min(cost[i][j+1][x][1],cost[i-1][j][x][y]+P[i]);
				// not
				cost[i][j][x][0]=min(cost[i][j][x][0],cost[i-1][j][x][y]);
			}
		}
		ll mi=min({cost[N-1][k][0][0],cost[N-1][k][0][1],cost[N-1][k][1][0]});
		if(mi>1<<29) mi=-1;
		return mi;
		
		
        
    }
};

