#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class UF {
	public:
	int um;
	vector<int> ufpar,ufrank,ufcnt;
	UF(int um_=100002) { um=um_; ufrank=vector<int>(um,0); ufcnt=vector<int>(um,1); for(int i=0;i<um;i++) ufpar.push_back(i);}
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int N;
ll X[1010],Y[1010];
ll D[1010][1010];

bool ok(ll v) {
	UF uf(1010);
	int x,y;
	FOR(x,N) FOR(y,N) if(D[x][y]<=v*v) uf.unite(x,y);
	return uf[0]==uf[N-1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) D[x][y]=(X[x]-X[y])*(X[x]-X[y])+(Y[x]-Y[y])*(Y[x]-Y[y]);
	
	ll hoge=(1LL<<31)-1;
	for(i=30;i>=0;i--) if(ok(hoge-(1LL<<i))) hoge -= 1LL<<i;
	cout<<(hoge+9)/10*10<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
