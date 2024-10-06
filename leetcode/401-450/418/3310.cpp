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
int mul[101010];

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
		int i;
		FOR(i,n) E[i].clear(),mul[i]=0;
		FORR(e,invocations) E[e[0]].push_back(e[1]);
		
		mul[k]=1;
		queue<int> Q;
		Q.push(k);
		while(Q.size()) {
			int x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(mul[e]==0) {
				mul[e]=1;
				Q.push(e);
			}
		}
		FOR(i,n) if(mul[i]==0) Q.push(i);
		FORR(e,invocations) E[e[1]].push_back(e[0]);
		while(Q.size()) {
			int x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(mul[e]==1) {
				mul[e]=0;
				Q.push(e);
			}
		}
		
		
		vector<int> V;
		FOR(i,n) if(mul[i]==0) V.push_back(i);
		return V;
        
    }
};