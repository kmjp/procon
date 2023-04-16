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

int E[101][101];

class Graph {
public:
int N;
    Graph(int n, vector<vector<int>>& edges) {
		int x,y;
		FOR(x,n) FOR(y,n) E[x][y]=1<<30;
        FORR(a,edges) {
			E[a[0]][a[1]]=min(E[a[0]][a[1]],a[2]);
		}
		N=n;
    }
    
    void addEdge(vector<int> edge) {
        E[edge[0]][edge[1]]=min(E[edge[0]][edge[1]],edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        ll D[101];
        int i;
        FOR(i,N) D[i]=1LL<<30;
        priority_queue<pair<ll,int>> Q;
        D[node1]=0;
        Q.push({0,node1});
        while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[cur]!=co) continue;
			if(cur==node2) return co;
			FOR(i,N) if(D[i]>co+E[cur][i]) {
				D[i]=co+E[cur][i];
				Q.push({-D[i],i});
			}
		}
		return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
 