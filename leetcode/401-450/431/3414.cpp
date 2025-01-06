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




vector<array<int,4>> V;
pair<ll,vector<int>> memo[505050][5];
int nex[505050];

class Solution {
public:
	pair<ll,vector<int>> dfs(int cur,int lef) {
		if(lef==0||cur==V.size()) {
			return {0,{}};
		}
		if(memo[cur][lef].first>=0) return memo[cur][lef];
		
		int W=V[cur][2];
		int i=V[cur][3];
		//Žæ‚ç‚È‚¢ê‡
		auto ret=dfs(cur+1,lef);
		auto ret2=dfs(nex[cur],lef-1);
		ret2.first+=W;
		if(ret2.first>ret.first) {
			ret2.second.push_back(i);
			sort(ALL(ret2.second));
			ret=ret2;
		}
		else if(ret2.first==ret.first) {
			ret2.second.push_back(i);
			sort(ALL(ret2.second));
			ret.second=min(ret.second,ret2.second);
		}
		return memo[cur][lef]=ret;
		
		
	}
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
		int i,j;
		V.clear();
		FOR(i,intervals.size()) {
			V.push_back({intervals[i][0],intervals[i][1],intervals[i][2],i});
		}
		sort(ALL(V));
		vector<int> L;
		FOR(i,V.size()) L.push_back(V[i][0]);
		FOR(i,V.size()) nex[i]=lower_bound(ALL(L),V[i][1]+1)-L.begin();
		FOR(i,intervals.size()+2) FOR(j,5) memo[i][j]={-1,{}};
		
		auto p=dfs(0,4);
		return p.second;
    }
};


