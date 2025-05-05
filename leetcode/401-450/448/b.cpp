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

vector<vector<int>> V;

class Solution {
public:
	void dfs(int x1,int x2,int y1,int y2,int& cur) {
		if(x2-x1==1) {
			V[y1][x1]=cur++;
		}
		else {
			int x3=(x2+x1)/2;
			int y3=(y2+y1)/2;
			dfs(x3,x2,y1,y3,cur);
			dfs(x3,x2,y3,y2,cur);
			dfs(x1,x3,y3,y2,cur);
			dfs(x1,x3,y1,y3,cur);
		}
	}
    vector<vector<int>> specialGrid(int n) {
        V.clear();
        V.resize(1<<n);
        FORR(v,V) v.resize(1<<n);
        int cur=0;
        dfs(0,1<<n,0,1<<n,cur);
        return V;
    }
};

