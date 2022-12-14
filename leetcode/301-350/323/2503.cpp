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
	vector<int> par,rank,cnt;
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

vector<int> Q[1010101],G[1010101];

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
		UF<101010> uf;
		int i,y,x;
		FOR(i,1000001) Q[i].clear(),G[i].clear();
		int H=grid.size(),W=grid[0].size();
		vector<int> R=queries;
		FOR(i,R.size()) Q[R[i]].push_back(i);
		FOR(y,H) FOR(x,W) G[grid[y][x]].push_back(y*W+x);
		FOR(i,1000001) {
			FORR(v,Q[i]) {
				if(i<=grid[0][0]) R[v]=0;
				else R[v]=uf.count(0);
			}
			FORR(v,G[i]) {
				int cy=v/W;
				int cx=v%W;
				int j;
				int d[4]={0,1,0,-1};
				FOR(j,4) {
					int ty=cy+d[j];
					int tx=cx+d[j^1];
					if(ty<0||ty>=H||tx<0||tx>=W) continue;
					if(grid[ty][tx]>i) continue;
					uf(ty*W+tx,cy*W+cx);
				}
			}
		}
		return R;
		
        
    }
};

