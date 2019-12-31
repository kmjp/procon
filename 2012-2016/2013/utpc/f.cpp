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

class UF {
	public:
	static const int ufmax=2002;
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

int N,M,Q,num[2002];
int mat[2002][2002];
vector<pair<int,pair<int,int> > > E[2001];
vector<pair<int,pair<int,int> > > TE;
UF uf;

void solve() {
	int f,i,j,k,l,x,y,z;
	
	cin>>N>>M;
	FOR(i,N) num[i]=1;
	FOR(i,M) {
		cin>>x>>y>>l;
		mat[x][y]=mat[y][x]=l;
	}
	TE.reserve(200000);
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		UF uf2;
		int x2=uf[x],y2=uf[y];
		
		TE.clear();
		
		ITR(it,E[x2]) TE.push_back(*it);
		ITR(it,E[y2]) TE.push_back(*it);
		E[x2].clear();
		E[y2].clear();
		
		vector<int> g1,g2;
		FOR(i,N) if(uf[i]==x2) g1.push_back(i);
		FOR(i,N) if(uf[i]==y2) g2.push_back(i);
		ITR(it,g1) ITR(it2,g2) if(mat[*it][*it2]) TE.push_back(make_pair(mat[*it][*it2],make_pair(*it,*it2)));
		sort(TE.begin(),TE.end());
		
		uf.unite(x,y);
		z=uf.find(x);
		num[z]=num[x2]+num[y2];
		
		ll tot=0;
		int nv=num[z];
		
		
		E[z].clear();
		ITR(it,TE) {
			int fi=it->second.first;
			int se=it->second.second;
			if(uf2[fi]==uf2[se]) continue;
			uf2.unite(fi,se);
			tot += it->first;
			nv--;
			E[z].push_back(*it);
		}
		
		if(nv>1) tot=-1;
		if(tot==-1) cout << "IMPOSSIBLE" << endl;
		else cout << tot << endl;
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


