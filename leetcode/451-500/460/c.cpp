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

vector<int> D[2<<20];
vector<pair<int,int>> E[2<<20];
int dp[2<<20];
int is[2<<20];
int isp[2<<20];
class Solution {
public:
    int minJumps(vector<int>& nums) {
		int i,j;
		int N=nums.size();
		if(isp[1]==0) {
			isp[1]=1;
			for(i=2;i<=1000000;i++) if(isp[i]==0) {
				for(j=2*i;j<=1000000;j+=i) isp[j]=1;
			}
		}
		
		FORR(a,nums) {
			is[a]=1;
			dp[a]=1<<20;
		}
		FOR(i,N) {
			dp[1000001+i]=1<<20;
		}
		for(i=2;i<=1000000;i++) if(isp[i]==0&&is[i]) {
			for(j=2*i;j<=1000000;j+=i) {
				if(is[j]) E[i].push_back({j,0});
			}
		}
		
		FOR(i,N) {
			if(isp[nums[i]]==0) E[1000001+i].push_back({nums[i],1});
			E[nums[i]].push_back({1000001+i,0});
			if(i) {
				E[1000001+i-1].push_back({1000001+i,1});
				E[1000001+i].push_back({1000001+i-1,1});
			}
		}
		dp[1000001]=0;
		deque<int> Q;
		Q.push_back(1000001);
		int ret=0;
		while(1) {
			int cur=Q.front();
			Q.pop_front();
			if(cur==1000000+N) {
				ret=dp[cur];
				break;
			}
			FORR2(e,c,E[cur]) if(chmin(dp[e],dp[cur]+c)) {
				if(c==0) Q.push_front(e);
				else Q.push_back(e);
			}
		}
		FORR(a,nums) {
			D[a].clear();
			E[a].clear();
			is[a]=0;
		}
		FOR(i,N) E[1000001+i].clear();
		return ret;
        
    }
};


