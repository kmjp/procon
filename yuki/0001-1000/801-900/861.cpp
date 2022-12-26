#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll C[5][5];
ll S;

int vis[1<<25];
ll ret=1LL<<60;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int gmask(int mask,int y,int x) {
	return (mask>>(y*5+x))&1;
}

void dfs(int mask,ll s) {
	if(vis[mask]) return;
	vis[mask]=1;
	int y,x;
	
	if(abs(s-(S-s))<ret) {
		UF<25> uf;
		FOR(y,5) FOR(x,5) {
			if(x&&gmask(mask,y,x)==gmask(mask,y,x-1)) uf(y*5+x-1,y*5+x);
			if(y&&gmask(mask,y,x)==gmask(mask,y-1,x)) uf(y*5+x-5,y*5+x);
		}
		int num=0;
		FOR(x,25) if(uf[x]==x) num++;
		if(num<=2) ret=abs(s-(S-s));
	}
	
	FOR(y,5) FOR(x,5) if(gmask(mask,y,x)==0) {
		int ok=0;
		if(y) ok|=gmask(mask,y-1,x);
		if(y<4) ok|=gmask(mask,y+1,x);
		if(x) ok|=gmask(mask,y,x-1);
		if(x<4) ok|=gmask(mask,y,x+1);
		if(ok) dfs(mask | (1<<(y*5+x)),s+C[y][x]);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,5) FOR(x,5) {
		cin>>C[y][x];
		S+=C[y][x];
	}
	
	
	dfs(1,C[0][0]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
