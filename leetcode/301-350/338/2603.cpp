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

int N;
int S;
int C[101010];
int NC[101010];
int V[101010];
vector<int> E[101010];
int ret;

int dfs(int cur,int pre) {
	V[cur]=C[cur];
	FORR(e,E[cur]) if(e!=pre) {
		V[cur]+=dfs(e,cur);
	}
	
	if(pre!=cur) {
		int a=V[cur]+NC[pre]-C[cur];
		int b=(S-V[cur])+NC[cur]-C[pre];
		if(a!=S&&b!=S) ret+=2;
	}
	
	return V[cur];
}

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
		S=0;
		FORR(a,coins) S+=a;
		
		N=coins.size();
		int i;
		FOR(i,N) C[i]=coins[i];
		FOR(i,N) E[i].clear();
		FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		
		ret=0;
		FOR(i,N) {
			NC[i]=C[i];
			FORR(e,E[i]) NC[i]+=C[e];
		}
		
		dfs(0,0);
		return ret;
        
    }
};
