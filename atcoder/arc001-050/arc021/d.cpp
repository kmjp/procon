#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

ll P[5001][201];
double S[5001][201];
double R[5001][5001];
double BB[5001];
ll MB[5001][4];

class UF {
	public:
	static const int ufmax=5002;
	int ufpar[ufmax],ufrank[ufmax];
	UF() { init();}
	void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y;
		else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

void solve() {
	int f,i,j,k,l;
	unsigned int x,y,t;
	unsigned int w,z;
	cin>>w;
	
	x = 123456789;
	y = 362436069;
	z = 521288629;
	FOR(i,5000) {
		FOR(j,200) {
			t=x^(x<<11);
			x=y;
			y=z;
			z=w;
			w=(w ^ (w >> 19)) ^ (t ^ (t >> 8));
			ll v = w % 100000;
			v -= 50000;
			if(v>=0) v++;
			P[i][j]=v;
			if(P[i][j]>0) MB[i][j/50] |= 1LL<<(j%50);
			BB[i]+=v*v;
		}
		BB[i]=sqrt(BB[i]);
		FOR(j,200) S[i][j]=P[i][j]/BB[i];
	}
	
	set<pair<double,pair<int,int> > > V;
	FOR(x,5000) for(y=x+1;y<5000;y++) {
		int diff=0;
		diff += __builtin_popcountll(MB[x][0]^MB[y][0]);
		diff += __builtin_popcountll(MB[x][1]^MB[y][1]);
		diff += __builtin_popcountll(MB[x][2]^MB[y][2]);
		diff += __builtin_popcountll(MB[x][3]^MB[y][3]);
		
		if(diff<90) {
			double co=0;
			FOR(i,200) co+=S[x][i]*S[y][i];
			V.insert(make_pair(1-co,make_pair(x,y)));
		}
	}
	
	UF uf;
	ITR(it,V) {
		x=it->second.first;
		y=it->second.second;
		
		if(uf[x]!=uf[y]) {
			_P("%d %d\n",x+1,y+1);
			uf.unite(x,y);
		}
	}
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


