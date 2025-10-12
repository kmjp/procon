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
UF<1010> uf;
int E[505][505];

class Solution {
public:
	int N;
	int ok(int v) {
		uf.reinit(2*N);
		int x,y;
		FOR(x,N) FOR(y,x) if(x!=y&&E[x][y]<v) {
			uf(2*x,2*y+1);
			uf(2*x+1,2*y);
		}
		FOR(x,N) if(uf[2*x]==uf[2*x+1]) return 0;
		return 1;
	}
	
    int maxPartitionFactor(vector<vector<int>>& points) {
		N=points.size();
		if(N==2) return 0;
		
		int ret=0;
		int i,x,y;
		FOR(x,N) FOR(y,N) E[x][y]=abs(points[x][0]-points[y][0])+abs(points[x][1]-points[y][1]);
		
		
		for(i=28;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
		return ret;
        
    }
};
