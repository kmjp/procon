#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int D[101];
int mat[101][101];
int num[101];
int ok[101];

class UF {
	public:
	static const int ufmax=1052;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	int count(int x) {return ufcnt[find(x)];}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	UF uf;
	cin>>N;
	FOR(i,N) {
		cin>>D[i];
		x=(i+D[i])%N;
		y=(i-D[i]+N*1000)%N;
		mat[x][y]=mat[y][x]=1;
		uf.unite(x,y);
	}
	
	FOR(x,N) if(mat[x][x]) ok[uf[x]]=1;
	FOR(x,N) cin>>y, num[uf[x]]+=y==0;
	
	FOR(x,N) if(uf[x]==x && num[x]%2 && ok[x]==0) return _P("No\n");
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
