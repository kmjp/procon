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


class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
		UF<1010> uf;
		
		int a,b,N=circles.size();
		FOR(a,N) FOR(b,a) {
			ll r1=circles[a][2];
			ll r2=circles[b][2];
			ll dr=1LL*(circles[a][0]-circles[b][0])*(circles[a][0]-circles[b][0])+1LL*(circles[a][1]-circles[b][1])*(circles[a][1]-circles[b][1]);
			if((r1-r2)*(r1-r2)<=dr&&dr<=(r1+r2)*(r1+r2)) uf(a,b);
		}
		FOR(a,N) {
			ll CX=circles[a][0];
			ll CY=circles[a][1];
			ll CR=circles[a][2];
			
			int xy00=(CR*CR-(CX*CX+CY*CY))<=0;
			int xy01=(CR*CR-(CX*CX+(CY-Y)*(CY-Y)))<=0;
			int xy10=(CR*CR-((CX-X)*(CX-X)+CY*CY))<=0;
			int xy11=(CR*CR-((CX-X)*(CX-X)+(CY-Y)*(CY-Y)))<=0;
			
			if(xy00!=xy01||(CY>=0&&CY<=Y&&abs(CX)<=CR)) uf(a,N);
			if(xy00!=xy10||(CX>=0&&CX<=X&&abs(CY)<=CR)) uf(a,N+1);
			if(xy11!=xy01||(CY>=0&&CY<=Y&&abs(CX-X)<=CR)) uf(a,N+2);
			if(xy11!=xy10||(CX>=0&&CX<=X&&abs(CY-Y)<=CR)) uf(a,N+3);
		}
		
		
		FOR(a,N+4) cout<<uf[a];
		cout<<endl;
		int ok=1;
		if(uf[N]==uf[N+1]) ok=0;
		if(uf[N]==uf[N+2]) ok=0;
		if(uf[N+1]==uf[N+3]) ok=0;
		if(uf[N+2]==uf[N+3]) ok=0;
		return ok;
        
    }
};
