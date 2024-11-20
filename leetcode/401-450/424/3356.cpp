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

ll S[502020];


class Solution {
public:
	int can(vector<int> nums,vector<vector<int>> queries,int K) {
		int N=nums.size();
		int i;
		
		FOR(i,N+1) S[i]=0;
		FOR(i,K) {
			S[queries[i][0]]+=queries[i][2];
			S[queries[i][1]+1]-=queries[i][2];
		}
		FOR(i,N) {
			S[i+1]+=S[i];
			if(S[i]<nums[i]) return 0;
		}
		return 1;
	}
	
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int N=nums.size();
		int i;
		
		int K=queries.size()+1;
		for(i=20;i>=0;i--) if(can(nums,queries,K-(1<<i))) K-=1<<i;
		
		
		if(K<0) K=0;
		
		
		if(K==queries.size()+1) K=-1;
		return K;
        
    }
};
