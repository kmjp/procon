#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class UF {
	public:
	static const int ufmax=100002;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	int count(int x) {return ufcnt[x];}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int N,M,Q,G;
void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>Q;
	G=N*M/__gcd(N,M);
	UF uf;
	FOR(i,Q) {
		cin>>x>>y;
		uf.unite(x-1,50000+y-1);
	}
	FOR(i,N) FOR(j,G/N) uf.unite(i,i+N*j);
	FOR(i,M) FOR(j,G/M) uf.unite(50000+i,50000+i+M*j);
	int ret=0;
	FOR(i,G) {
		if(uf[i] != uf[50000+i]) ret=i+1, uf.unite(i,50000+i);
	}
	cout << ret << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


