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

int H,W,Q;
int A[505][505];
int SY[252525],SX[252525],TY[252525],TX[252525];
int ret[252525];
vector<pair<int,int>> ev[(1<<18)];
vector<int> check[1<<18];
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
UF<252525> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H+2) FOR(x,W+2) A[y][x]=1<<19;
	FOR(y,H) FOR(x,W) {
		cin>>A[y+1][x+1];
		ev[A[y+1][x+1]].push_back({y+1,x+1});
	}
	H+=2,W+=2;
	cin>>Q;
	FOR(i,Q) {
		cin>>SY[i]>>SX[i]>>TY[i]>>TX[i];
		ret[i]=(1<<18)-1;
	}
	for(int span=(1<<17);span>=1;span/=2) {
		FOR(i,1<<18) check[i].clear();
		FOR(i,Q) check[ret[i]-span].push_back(i);
		uf.reinit(H*W);
		FOR(i,1<<18) {
			FORR2(y,x,ev[i]) {
				if(A[y-1][x]<=i) uf(y*W+x,(y-1)*W+x);
				if(A[y+1][x]<=i) uf(y*W+x,(y+1)*W+x);
				if(A[y][x-1]<=i) uf(y*W+x,(y)*W+x-1);
				if(A[y][x+1]<=i) uf(y*W+x,(y)*W+x+1);
			}
			FORR(c,check[i]) if(uf[SY[c]*W+SX[c]]==uf[TY[c]*W+TX[c]]) ret[c]=i;
		}
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
