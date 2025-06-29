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
UF<202020> uf;

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
		uf.reinit(n);
		int ma=(1<<20)-1;
		FORR(e,edges) if(e[3]) {
			ma=min(ma,e[2]);
			if(uf[e[0]]==uf[e[1]]) return -1;
			uf(e[0],e[1]);
		}
		FORR(e,edges) uf(e[0],e[1]);
		if(uf.count(0)!=n) return -1;
		
		int i;
		int ret=0;
		for(i=19;i>=0;i--) {
			int tmp=ret+(1<<i);
			if(tmp>ma) continue;
			uf.reinit(n);
			FORR(e,edges) if(e[3]||e[2]>=tmp) uf(e[0],e[1]);
			int num=0;
			FORR(e,edges) if(uf[e[0]]!=uf[e[1]]&&e[2]*2>=tmp) uf(e[0],e[1]),num++;
			if(num<=k&&uf.count(0)==n) ret=tmp;
		}
		return ret;
        
    }
};
