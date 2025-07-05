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
UF<1<<20> uf;

int H,W,K;
map<pair<int,int>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	
	if(H==1||W==1) {
		if(K) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}
		return;
	}
	
	FOR(i,K) {
		cin>>y>>x;
		M[{y,x}]=i+2;
		if(y==H||x==1) uf(0,i+2);
		if(x==W||y==1) uf(1,i+2);
	}
	
	FORR2(p,cur,M) {
		y=p.first;
		x=p.second;
		for(int ty=max(0,y-1);ty<=min(y+1,H+1);ty++) for(int tx=max(0,x-1);tx<=min(x+1,W+1);tx++) {
			if(M.count({ty,tx})) uf(M[{y,x}],M[{ty,tx}]);
		}
	}
	
	if(uf[0]==uf[1]) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
