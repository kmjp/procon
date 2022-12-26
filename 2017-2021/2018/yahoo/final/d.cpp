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

int N;
int L[303030];

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf[20];
vector<int> C[301010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>L[i];
		if(L[i]) {
			j=0;
			while(1<<(j+1)<=L[i]) j++;
			uf[j](0,N-1-i);
			uf[j](L[i]-(1<<j),N-1-i+L[i]-(1<<j));
		}
	}
	for(i=19;i>=1;i--) {
		FOR(x,N) C[x].clear();
		FOR(x,N) C[uf[i][x]].push_back(x);
		FOR(x,N) if(C[x].size()>1) {
			FOR(y,C[x].size()-1) {
				uf[i-1](C[x][y],C[x][y+1]);
				uf[i-1](C[x][y]+(1<<(i-1)),C[x][y+1]+(1<<(i-1)));
			}
		}
	}
	
	FOR(i,N) {
		if(L[i]<N && uf[0][L[i]]==uf[0][N-1-i+L[i]]) return _P("No\n");
	}
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
