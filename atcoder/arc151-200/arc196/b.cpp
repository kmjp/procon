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

int T;
int H,W;
string S[1<<20];
const ll mo=998244353;

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
UF<4<<21> uf;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int id(int y,int x,int dir,int t) {
	y=(y+H)%H;
	x=(x+W)%W;
	return ((y*W+x)+dir*(H*W))*2+t;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int NB=0;
		FOR(y,H) {
			cin>>S[y];
		}
		
		// —ñ
		uf.reinit(4*H*W);
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='A') {
				uf(id(y,x,0,0),id(y+1,x,0,1));
				uf(id(y,x,0,1),id(y+1,x,0,0));
				uf(id(y,x,1,0),id(y,x+1,1,1));
				uf(id(y,x,1,1),id(y,x+1,1,0));
			}
			else {
				uf(id(y,x,0,0),id(y+1,x,0,0));
				uf(id(y,x,0,1),id(y+1,x,0,1));
				uf(id(y,x,1,0),id(y,x+1,1,0));
				uf(id(y,x,1,1),id(y,x+1,1,1));
				uf(id(y,x,0,0),id(y,x,1,1));
				uf(id(y,x,0,1),id(y,x,1,0));
			}
		}
		int num=0;
		int ng=0;
		FOR(y,H) FOR(x,W) FOR(k,2) {
			if(uf[id(y,x,k,0)]==uf[id(y,x,k,1)]) ng++;
			if(uf[id(y,x,k,0)]==id(y,x,k,0)) num++;
			if(uf[id(y,x,k,1)]==id(y,x,k,1)) num++;
		}
		if(ng) {
			cout<<0<<endl;
		}
		else {
			cout<<modpow(2,num/2)<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
