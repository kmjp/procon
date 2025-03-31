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

ll cost[101010];

ll dp[17][101010];

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int i;
        multiset<int> A,B;
        ll SA=0,SB=0;
		int y,v;
        FOR(i,x) {
			A.insert(nums[i]);
			SA+=nums[i];
			if(A.size()>B.size()) {
				v=*A.rbegin();
				A.erase(A.find(v));
				SA-=v;
				SB+=v;
				B.insert(v);
			}
		}
		while(*A.rbegin()>*B.begin()) {
			y=*A.rbegin();
			v=*B.begin();
			A.erase(A.find(y));
			B.erase(B.find(v));
			A.insert(v);
			B.insert(y);
			SA+=v-y;
			SB+=y-v;
		}
		
		cost[0]=(SB-1LL*B.size()*(*B.begin()))+(1LL*A.size()*(*B.begin())-SA);
		for(i=x;i<nums.size();i++) {
			if(A.count(nums[i-x])) {
				A.erase(A.find(nums[i-x]));
				SA-=nums[i-x];
			}
			else {
				B.erase(B.find(nums[i-x]));
				SB-=nums[i-x];
			}
			A.insert(nums[i]);
			SA+=nums[i];
			while(A.size()<B.size()) {
				v=*B.begin();
				B.erase(B.find(v));
				SB-=v;
				SA+=v;
				A.insert(v);
			}
			while(A.size()>B.size()) {
				v=*A.rbegin();
				A.erase(A.find(v));
				SA-=v;
				SB+=v;
				B.insert(v);
			}
			if(*A.rbegin()>*B.begin()) {
				y=*A.rbegin();
				v=*B.begin();
				A.erase(A.find(y));
				B.erase(B.find(v));
				A.insert(v);
				B.insert(y);
				SA+=v-y;
				SB+=y-v;
			}
			assert(A.size()<=B.size());
			cost[i-(x-1)]=(SB-1LL*B.size()*(*B.begin()))+(1LL*A.size()*(*B.begin())-SA);
		}
		int N=nums.size();
        FOR(y,k+1) FOR(i,N+1) dp[y][i]=1LL<<60;
        dp[0][0]=0;
        FOR(y,k+1) {
			FOR(i,N) {
				chmin(dp[y][i+1],dp[y][i]);
				if(y<k&&i+x<=N) chmin(dp[y+1][i+x],dp[y][i]+cost[i]);
			}
		}
		return dp[k][N];
        
    }
};

