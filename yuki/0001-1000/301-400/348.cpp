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

int H,W;
string S[1010];

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

UF<1010101> uf;
vector<int> C[1010*1010];
vector<int> G[1010*1010];
int vis[1010*1000];
int dp[1010*1000][2];


void dfs(int c,int ph) {
	int sy=c/W;
	int sx=c%W;
	vis[c]=1;
	int i,tx,ty;
	
	FORR(r,G[c]) {
		int cy=r/W,cx=r%W;
		for(ty=max(0,cy-1);ty<=min(cy+1,H-1);ty++) for(tx=max(0,cx-1);tx<=min(cx+1,W-1);tx++) if(vis[uf[ty*W+tx]]==0 && S[ty][tx]!=S[sy][sx]) {
			dfs(uf[ty*W+tx],1-ph);
			if(ph==0) {
				C[sy*W+sx].push_back(uf[ty*W+tx]);
			}
			else {
				FORR(r2,C[uf[ty*W+tx]]) C[sy*W+sx].push_back(r2);
			}
		}
	}
}

int dfs2(int r) {
	dp[r][1]=uf.count(r);
	FORR(r2,C[r]) {
		dfs2(r2);
		dp[r][0]+=max(dp[r2][0],dp[r2][1]);
		dp[r][1]+=dp[r2][0];
	}
	return max(dp[r][0],dp[r][1]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H) cin>>S[y+1], S[y+1]="."+S[y+1]+".";
	H+=2;
	W+=2;
	S[0]=string(W,'.');
	S[H-1]=string(W,'.');
	
	FOR(y,H) FOR(x,W) {
		for(i=-1;i<=1;i++) for(j=-1;j<=1;j++) if((i==0 || j==0) || S[y][x]=='x') 
			if(y+i>=0 && y+i<H && x+j>=0 && x+j<W && S[y+i][x+j]==S[y][x]) uf(y*W+x,(y+i)*W+(x+j));
	}
	FOR(y,H) FOR(x,W) G[uf[y*W+x]].push_back(y*W+x);
	dfs(uf[0],0);
	
	int ret=0;
	FORR(r,C[uf[0]]) ret += dfs2(r);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
