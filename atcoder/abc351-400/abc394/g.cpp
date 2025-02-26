#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int H,W;
int F[505][505];
int Q;
int Y1[202020],X1[202020];
int Y2[202020],X2[202020];
int S[202020],E[202020];
set<int> Qs[505*505];
int ret[202020];

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
UF<505*505> uf;

void merge(int y1,int x1,int y2,int x2,int h) {
	if(F[y2][x2]<h) return;
	int a=uf[y1*W+x1];
	int b=uf[y2*W+x2];
	if(a==b) return;
	if(Qs[a].size()<Qs[b].size()) swap(a,b);
	FORR(v,Qs[b]) {
		if(Qs[a].count(v)) {
			Qs[a].erase(v);
			if(h<min(S[v],E[v])) {
				ret[v]=S[v]+E[v]-2*h;
			}
			else {
				ret[v]=abs(S[v]-E[v]);
			}
		}
		else {
			Qs[a].insert(v);
		}
	}
	Qs[b].clear();
	int k=uf(a,b);
	if(b==k) swap(Qs[a],Qs[b]);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> ev;
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>F[y][x];
		ev.push_back({F[y][x],y*W+x});
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>Y1[i]>>X1[i]>>S[i]>>Y2[i]>>X2[i]>>E[i];
		Y1[i]--,X1[i]--;
		Y2[i]--,X2[i]--;
		if(Y1[i]==Y2[i]&&X1[i]==X2[i]) {
			ret[i]=abs(S[i]-E[i]);
		}
		else {
			Qs[Y1[i]*W+X1[i]].insert(i);
			Qs[Y2[i]*W+X2[i]].insert(i);
		}
	}
	sort(ALL(ev));
	reverse(ALL(ev));
	FORR2(h,pos,ev) {
		int ty=pos/W;
		int tx=pos%W;
		
		if(ty) merge(ty,tx,ty-1,tx,h);
		if(ty+1<H) merge(ty,tx,ty+1,tx,h);
		if(tx) merge(ty,tx,ty,tx-1,h);
		if(tx+1<W) merge(ty,tx,ty,tx+1,h);
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
