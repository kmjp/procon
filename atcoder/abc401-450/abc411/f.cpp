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

int N,M,Q;
int U[303030],V[303030];
set<int> E[303030];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(E[x].size()>E[y].size()) return par[y]=x;
		return par[x]=y;
	}
};
UF<303030> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].insert(V[i]);
		E[V[i]].insert(U[i]);
	}
	
	cin>>Q;
	while(Q--) {
		cin>>k;
		x=uf[U[k-1]];
		y=uf[V[k-1]];
		if(uf[x]!=uf[y]) {
			M--;
			E[x].erase(y);
			E[y].erase(x);
			k=uf(x,y);
			if(y==k) {
				y=x;
			}
			FORR(v,E[y]) {
				E[v].erase(y);
				if(E[k].count(v)) {
					M--;
				}
				else {
					E[k].insert(v);
					E[v].insert(k);
				}
			}
			E[y].clear();
		}
		cout<<M<<endl;
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
