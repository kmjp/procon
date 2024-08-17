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
string S[505];
const ll mo=998244353;

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
UF<1<<20> uf; 

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	ll ret=1;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='#') {
			ret=ret*2%mo;
			if(y==0||S[y-1][x]=='.') ret=ret*2%mo;
			if(x==0||S[y][x-1]=='.') ret=ret*2%mo;
			if(y&&S[y-1][x]=='#') uf(y*500+x,(y-1)*500+x);
			if(x&&S[y][x-1]=='#') uf(y*500+x,(y-0)*500+x-1);
		}
	}
	FOR(y,H) FOR(x,W) if(S[y][x]=='#' && uf[y*500+x]==y*500+x) ret=ret*(mo+1)/2%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
