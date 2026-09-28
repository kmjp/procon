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



class Solution {
public:
	ll memo[101010][2][2];
	vector<vector<int>> V;
	vector<int> W;
	int N;
	ll dfs(int i,int start,int end) {
		if(i>=N) {
			if(end) return -1LL<<60;
			return 0;
		}
		
		if(memo[i][start][end]!=-1) return memo[i][start][end];
		ll ret=dfs(i+1,start,end);
		//is’†
		if(start&&end&&i+1<N) ret+=V[i+1][0]-V[i][0];
		int nex=lower_bound(ALL(W),V[i][1])-W.begin();
		
		if(nex<N) ret=max(ret,V[i][2]+V[nex][0]-V[i][1]+dfs(nex,1,1));
		ret=max(ret,V[i][2]+dfs(nex,1,0));
		return memo[i][start][end]=ret;
		
	}
	
    long long maxEarnings(vector<vector<int>>& meetings) {
		
		V=meetings;
		sort(ALL(V));
		W.clear();
		FORR(v,V) W.push_back(v[0]);
		N=V.size();
		int i,x,y;
		FOR(i,N+1) FOR(x,2) FOR(y,2) memo[i][x][y]=-1;
		return dfs(0,0,0);
        
    }
};


