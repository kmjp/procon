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

int N,M;
ll mo=1000000007;
map<int,vector<pair<int,int> > > MM;

ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll mat[101][101];
ll det_mo(int N) {
	int x,y,z;
	ll ret=1;
	FOR(y,N) FOR(z,N) mat[y][z]=((mat[y][z]%mo)+mo)%mo;
	FOR(x,N) {
		if(mat[x][x]==0) {
			for(y=x+1;y<N;y++) if(mat[y][x]) break;
			if(y==N) return 0;
			FOR(z,N) swap(mat[x][z],mat[y][z]);
		}
		ret=ret*mat[x][x]%mo;
		ll rev=modpow(mat[x][x],mo-2,mo);
		FOR(z,N) mat[x][z]=rev*mat[x][z]%mo;
		for(y=x+1;y<N;y++) if(mat[y][x]) {
			rev=mat[y][x];
			for(z=x;z<N;z++) mat[y][z]=((mat[y][z]-mat[x][z]*rev)%mo+mo)%mo;
		}
	}
	return ret;
}

class UF {
	public:
	static const int ufmax=10002;
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
	int f,i,j,k,l,x,y;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>j;
		if(x>y) swap(x,y);
		MM[j].push_back(make_pair(x-1,y-1));
	}
	
	UF uf1,uf2;
	
	int cg=N;
	ll co=0,tc=0,ret=1;
	ITR(it,MM) {
		int pcg=cg;
		uf2=uf1;
		co=it->first;
		ITR(it2,it->second) if(uf1[it2->first] != uf1[it2->second]) {
			uf1.unite(it2->first,it2->second);
			tc+=co;
			cg--;
		}
		if(pcg==cg) continue;
		vector<int> V;
		ITR(it2,it->second) if(uf2[it2->first] != uf2[it2->second]) V.push_back(uf1[it2->first]);
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());
		ITR(vit,V) {
			ZERO(mat);
			map<int,int> MM;
			ITR(it2,it->second) if(uf1[it2->first]==*vit) {
				x = uf2[it2->first];
				y = uf2[it2->second];
				if(x==y) continue;
				if(MM.find(x) == MM.end()) MM[x]=MM.size()-1;
				if(MM.find(y) == MM.end()) MM[y]=MM.size()-1;
				mat[MM[x]][MM[x]]++;
				mat[MM[y]][MM[y]]++;
				mat[MM[x]][MM[y]]--;
				mat[MM[y]][MM[x]]--;
			}
			ret=ret*det_mo(MM.size()-1)%mo;
		}
		if(cg==1) break;
	}
	_P("%lld %lld\n",tc,ret);
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


