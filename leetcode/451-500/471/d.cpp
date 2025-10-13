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
int S[202020];
int C[202020];
ll ret;

class Solution {
public:
	void dfs(int cur,int pre) {
		ret+=S[C[cur]]++;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
		
		
		S[C[cur]]--;
	}
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
		int i;
		FORR(n,nums) {
			for(i=2;i*i<=n;i++) while(n%(i*i)==0) n/=i*i;
		}
		FOR(i,n) {
			E[i].clear();
			C[i]=nums[i];
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		ret=0;
		dfs(0,0);
		return ret;
		
        
    }
};


