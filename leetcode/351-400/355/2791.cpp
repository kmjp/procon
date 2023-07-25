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

int mask[101010];
unordered_map<int,int> M;
vector<pair<int,int>> E[101010];
ll ret;
string S;
class Solution {
public:
	void dfs(int cur,int pre,int m) {
		mask[cur]=m;
		ret+=M[m]++;
		int j;
		FOR(j,26) ret+=M[m^(1<<j)];
		FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,mask[cur]^(1<<e.second));
	}

    long long countPalindromePaths(vector<int>& parent, string s) {
		S=s;
		int n=parent.size();
		int i;
		FOR(i,n) E[i].clear();
		FOR(i,n) if(i) {
			E[parent[i]].push_back({i,s[i]-'a'});
			E[i].push_back({parent[i],s[i]-'a'});
		}
		M.clear();
		ret=0;
		dfs(0,0,0);
		
		return ret;
        
    }
};
