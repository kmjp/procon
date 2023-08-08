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

int D[404][404];

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
	void dump(int num=um) { //グループ分けした配列を作る
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
	}
};
UF<404*404> uf;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
		int H=grid.size(),W=grid[0].size();
        int y,x,i;
        queue<int> Q;
        FOR(y,H) FOR(x,W) {
			if(grid[y][x]==1) {
				D[y][x]=0;
				Q.push(y*1000+x);
			}
			else {
				D[y][x]=1000;
			}
		}
		uf.reinit(400*400);
		vector<pair<int,int>> C;
		while(Q.size()) {
			int cy=Q.front()/1000;
			int cx=Q.front()%1000;
			Q.pop();
			C.push_back({D[cy][cx],cy*1000+cx});
			FOR(i,4) {
				int d[]={0,1,0,-1};
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx]==1000) {
					D[ty][tx]=D[cy][cx]+1;
					Q.push(ty*1000+tx);
				}
			}
		}
		
		sort(ALL(C));
		reverse(ALL(C));
		FORR(c,C) {
			int cy=c.second/1000;
			int cx=c.second%1000;
			FOR(i,4) {
				int d[]={0,1,0,-1};
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx]>=D[cy][cx]) uf(cy*400+cx,ty*400+tx);
			}
			
			
			if(uf[0]==uf[(H-1)*400+(W-1)]) return c.first;
		}
		return 0;
    }
};
