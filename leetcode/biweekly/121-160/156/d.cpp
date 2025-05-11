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

vector<int> E[202020];
ll mi[50505][55];
ll ma[50505][55];
ll A[50505];
int K;

class Solution {
public:
	void dfs(int cur,int pre) {
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
		int i;
		//”½“]‚³‚¹‚È‚¢
		FOR(i,K+1) {
			mi[cur][i]=A[cur];
			ma[cur][i]=A[cur];
			FORR(e,E[cur]) if(e!=pre) {
				mi[cur][i]+=mi[e][min(i+1,K)];
				ma[cur][i]+=ma[e][min(i+1,K)];
			}
			if(i) {
				mi[cur][i]=min(mi[cur][i],mi[cur][i-1]);
				ma[cur][i]=max(ma[cur][i],ma[cur][i-1]);
			}
		}
		//”½“]‚·‚é
		ll a=-A[cur];
		ll b=-A[cur];
		FORR(e,E[cur]) if(e!=pre) {
			a+=-ma[e][1];
			b+=-mi[e][1];
		}
		mi[cur][K]=min(mi[cur][K],a);
		ma[cur][K]=max(ma[cur][K],b);
		
	}
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int i;
        int N=nums.size();
        K=k;
        FOR(i,N) {
			A[i]=nums[i];
			E[i].clear();
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		dfs(0,0);
		return ma[0][k];
		
    }
};
