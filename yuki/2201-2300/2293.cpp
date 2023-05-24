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

UF_pop<404040> uf;
const ll mo=998244353;
int p2[404040];
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	p2[0]=1;
	FOR(i,404010) p2[i+1]=p2[i]*2%mo;
	
	int num=2*N;
	int ng=0;
	while(Q--) {
		cin>>i;
		int U,V;
		if(i==1) {
			cin>>U>>V;
			U--,V--;
			if(uf[2*U]!=uf[2*V]) {
				num--;
				uf(2*U,2*V);
			}
			if(uf[2*U+1]!=uf[2*V+1]) {
				num--;
				uf(2*U+1,2*V+1);
			}
			if(uf[2*U]==uf[2*U+1]) ng=1;
			if(uf[2*V]==uf[2*V+1]) ng=1;
		}
		else if(i==2) {
			cin>>U>>V;
			U--,V--;
			if(uf[2*U]!=uf[2*V+1]) {
				num--;
				uf(2*U,2*V+1);
			}
			if(uf[2*U+1]!=uf[2*V]) {
				num--;
				uf(2*U+1,2*V);
			}
			if(uf[2*U]==uf[2*U+1]) ng=1;
			if(uf[2*V]==uf[2*V+1]) ng=1;
		}
		else {
			while(uf.hist.size()) uf.pop();
			num=2*N;
			ng=0;
		}
		
		if(ng) {
			cout<<0<<endl;
		}
		else {
			cout<<p2[num/2]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
