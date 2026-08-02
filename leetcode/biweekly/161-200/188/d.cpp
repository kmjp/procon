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


map<array<int,5>,pair<int,int>> memo;
vector<int> D;
class Solution {
public:
	pair<int,int> dfs(int cur,int f0,int f1,int d0,int d1) {
		if(cur==D.size()) return {0,0};
		if(memo.count({cur,f0,f1,d0,d1})) return memo[{cur,f0,f1,d0,d1}];
		int d=D[cur];
		int c0=0,c1=0,r0=0,r1=0;
		if(f0>=d) {
			auto p=dfs(cur+1,f0-d,f1,d,max(0,d1-d0));
			c0=p.first+1;
			r0=max(p.second,d0);
		}
		if(f1>=d) {
			auto p=dfs(cur+1,f0,f1-d,max(0,d0-d1),d);
			c1=p.first+1;
			r1=max(p.second,d1);
		}
		if(c0<c1) return memo[{cur,f0,f1,d0,d1}]={c1,r1};
		if(c0>c1) return memo[{cur,f0,f1,d0,d1}]={c0,r0};
		return memo[{cur,f0,f1,d0,d1}]={c0,min(r0,r1)};
		
	}

    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
		memo.clear();
		D=demand;
		
		auto ret=dfs(0,fuel[0],fuel[1],0,0);
		if(ret.first==0) return -1;
		return ret.second;
		
        
    }
};
