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

int N;
string S1,S2;
int mask[256],on[256];

class UF {
	public:
	static const int ufmax=10002;
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

void solve() {
	int f,i,j,k,l,x,y;
	UF uf;
	
	cin>>N>>S1>>S2;
	
	FOR(i,N) if(isalpha(S1[i])) on[S1[i]]++;
	FOR(i,N) if(isalpha(S2[i])) on[S2[i]]++;
	FOR(i,N) if(isalpha(S1[i]) && isalpha(S2[i])) uf.unite(S1[i],S2[i]);
	
	FOR(i,256) mask[i]=10;
	if(isalpha(S1[0])) mask[uf[S1[0]]] = 9;
	if(isalpha(S2[0])) mask[uf[S2[0]]] = 9;
	
	FOR(i,N) {
		if(isdigit(S1[i]) && isalpha(S2[i])) mask[uf[S2[i]]] = 1;
		if(isdigit(S2[i]) && isalpha(S1[i])) mask[uf[S1[i]]] = 1;
	}
	
	ll ret=1;
	FOR(i,256) if(on[i] && uf[i]==i) ret *= mask[i];
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


