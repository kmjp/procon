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
string S[1010];
const ll mo=998244353;

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};
UF_pop<1<<20> uf;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int NR=0;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(y&&S[y-1][x]=='#'&&S[y][x]=='#') uf(y*1000+x,(y-1)*1000+x);
			if(x&&S[y][x-1]=='#'&&S[y][x]=='#') uf(y*1000+x,y*1000+x-1);
			if(S[y][x]=='.') NR++;
		}
	}
	int NG=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='#'&&uf[y*1000+x]==y*1000+x) NG++;
	ll sum=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		j=NG+1;
		int step=0;
		FOR(i,4) {
			int d[4]={0,-1,0,1};
			int ty=y+d[i];
			int tx=x+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(S[ty][tx]=='.') continue;
			step++;
			if(uf[ty*1000+tx]!=uf[y*1000+x]) j--;
			uf(ty*1000+tx,y*1000+x);
		}
		sum+=j;
		while(step--) uf.pop();
	}
	
	sum=sum%mo*modpow(NR);
	cout<<sum%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
