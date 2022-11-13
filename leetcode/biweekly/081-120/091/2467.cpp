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
int A[101010];
int P[101010];
ll ma[101010];
class Solution {
public:
	void dfs(int cur,int pre,int d) {
		D[cur]=d;
		P[cur]=pre;
		FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
	}
	ll dfs2(int cur,int pre) {
		ll ma=-(1LL<<60);
		FORR(e,E[cur]) if(e!=pre) ma=max(ma,dfs2(e,cur));
		if(ma==-(1LL<<60)) ma=0;
		return ma+A[cur];
	}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int N=amount.size();
        int i;
        FOR(i,N) {
			E[i].clear();
			A[i]=amount[i];
		}
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		dfs(0,0,0);
		int cur=bob;
		int d=D[cur];
		while(cur) {
			if(D[cur]*2==d) {
				A[cur]/=2;
			}
			else if(D[cur]*2>d) {
				A[cur]=0;
			}
			cur=P[cur];
		}
		return dfs2(0,0);
		
    }
};
