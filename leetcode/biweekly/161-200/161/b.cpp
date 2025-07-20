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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<101010> uf;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
		int H=grid.size(),W=grid[0].size();
		uf.reinit(H*W);
		int y,x;
		FOR(y,H) FOR(x,W) {
			if(y&&grid[y][x]&&grid[y-1][x]) uf(y*W+x,(y-1)*W+x);
			if(x&&grid[y][x]&&grid[y][x-1]) uf(y*W+x,y*W+x-1);
		}
		map<int,ll> M;
		FOR(y,H) FOR(x,W) if(grid[y][x]) M[uf[y*W+x]]+=grid[y][x];
		int ret=0;
		FORR(a,M) if(a.second%k==0) ret++;
		return ret;
        
    }
};
