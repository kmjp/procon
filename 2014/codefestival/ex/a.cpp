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

class UF {
	public:
	static const int ufmax=100052;
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

int N,M;
int A[2001],B[2001];
int Y[2001];
int mat[2001][2001];
int ten[2001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	UF uf;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		mat[A[i]][B[i]]=mat[B[i]][A[i]]=1;
	}
	FOR(i,N) {
		cin>>Y[i];
		Y[i]--;
	}
	FOR(x,M) for(y=x+1;y<M;y++) {
		int un=0;
		if(A[x]==A[y] && mat[B[x]][B[y]]) un++;
		if(A[x]==B[y] && mat[B[x]][A[y]]) un++;
		if(B[x]==A[y] && mat[A[x]][B[y]]) un++;
		if(B[x]==B[y] && mat[A[x]][A[y]]) un++;
		if(un) {
			uf.unite(A[x],A[y]);
			uf.unite(B[x],B[y]);
			uf.unite(A[x],B[x]);
			uf.unite(A[x],B[y]);
			uf.unite(A[y],B[x]);
			uf.unite(A[y],B[y]);
		}
	}
	FOR(i,N) if(uf[i]!=uf[Y[i]]) return _P("NO\n");
	// tenti
	j=0;
	FOR(x,N) for(y=x+1;y<N;y++) if(uf[x]==uf[y] && Y[x]>Y[y]) ten[uf[x]]++;
	FOR(i,N) if(ten[i]%2) return _P("NO\n");
	
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
