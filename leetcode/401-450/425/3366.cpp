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

int from[101][101];
int to[101][101];

class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
		int N=nums.size();
		
		int x,y;
		FOR(x,N+1) FOR(y,N+1) from[x][y]=1LL<<60;
		from[op1][op2]=0;
		FORR(c,nums) {
			FOR(x,N+1) FOR(y,N+1) to[x][y]=from[x][y]+c;
			FOR(x,op1+1) FOR(y,op2+1) {
				if(x) to[x-1][y]=min(to[x-1][y],from[x][y]+(c+1)/2);
				if(y&&c>=k) to[x][y-1]=min(to[x][y-1],from[x][y]+c-k);
				if(x&&y&&(c+1)/2>=k) to[x-1][y-1]=min(to[x-1][y-1],from[x][y]+(c+1)/2-k);
				if(x&&y&&c>=k) to[x-1][y-1]=min(to[x-1][y-1],from[x][y]+(c-k+1)/2);
			}
			swap(from,to);
		}
		
		int mi=1<<30;
		FOR(x,op1+1) FOR(y,op2+1) mi=min(mi,from[x][y]);
		return mi;
		
        
    }
};

