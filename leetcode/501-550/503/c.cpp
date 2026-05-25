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


int dp[2][101010];

class Solution {
public:
    int minOperations(vector<int>& nums) {
		int i,N=nums.size(),j;
        
        if(N==1) return 0;
        if(N==2) return nums[0];
        int root=0;
		int ok1=1,ok2=1;
		FOR(i,N) if(nums[i]==0) {
			root=i;
			FOR(j,N-1) {
				if(nums[(i+j)%N]+1!=nums[(i+j+1)%N]) ok1=0;
				if(nums[(i-j+N)%N]+1!=nums[(i-j+N-1)%N]) ok2=0;
			}
			break;
		}
		if(ok1==0&&ok2==0) return -1;
        
        FOR(i,N) dp[0][i]=dp[1][i]=1<<20;
        queue<int> Q;
        if(ok1) {
			dp[0][root]=0;
			Q.push(root);
		}
        if(ok2) {
			dp[1][root]=0;
			Q.push(N+root);
		}
        while(Q.size()) {
			int order=Q.front()/N;
			int cur=Q.front()%N;
			int re=N-1-cur;
			Q.pop();
			if(chmin(dp[order^1][re],dp[order][cur]+1)) Q.push((order^1)*N+re);
			if(chmin(dp[order][(cur+N-1)%N],dp[order][cur]+1)) Q.push(order*N+(cur+N-1)%N);
		}
        
        return dp[0][0];
    }
};

