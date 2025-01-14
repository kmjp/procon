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
int vis[101010]={};
class Solution {
public:
	int ok(int v,int n,vector<vector<int>>& edges) {
		int i;
		
		FOR(i,n) vis[i]=0,E[i].clear();
		FORR(e,edges) if(e[2]<=v) E[e[1]].push_back(e[0]);
		queue<int> Q;
		Q.push(0);
		vis[0]=1;
		while(Q.size()) {
			int x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(vis[e]==0) {
				vis[e]=1;
				Q.push(e);
			}
		}
		FOR(i,n) if(vis[i]==0) return 0;
		return 1;
		
	}
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int ret=1<<30;
        
        if(ok(ret,n,edges)==0) return -1;
        int i;
        for(i=30;i>=0;i--) if(ok(ret-(1<<i),n,edges)) ret-=1<<i;
        return ret;
        
        
    }
};


