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


vector<int> E[101010];
int D[101010];

class Solution {
public:
	void dfs(int cur,int d) {
		D[cur]=d;
		FORR(e,E[cur]) dfs(e,d+1);
	}
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int N=parent.size();
        int i;
        FOR(i,N) E[i].clear();
        FOR(i,N) if(parent[i]>=0) {
			E[parent[i]].push_back(i);
		}
		dfs(0,0);
		int ma=0;
		FOR(i,N) ma=max(ma,D[i]);
		ll ret=0;
		FOR(i,N) ret+=1LL*nums[i]*(ma+1-D[i]);
		return ret;
    }
};
