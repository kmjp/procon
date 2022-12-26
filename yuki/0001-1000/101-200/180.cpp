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

int N;
ll X[1010],Y[1010];
ll ret;
ll m=1LL<<60;
double cr[1010][1010];

void val(ll x) {
	ll ma=0,mi=1LL<<60;
	int i;
	if(x<1) return;
	FOR(i,N) ma=max(ma,Y[i]*x+X[i]) , mi=min(mi,Y[i]*x+X[i]);
	if(ma-mi<m || (ma-mi==m && x<ret)) m=ma-mi,ret=x;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	FOR(x,N) FOR(y,N) cr[x][y] = (Y[x]==Y[y]) ? -1 : (X[y]-X[x])*1.0/(Y[x]-Y[y]);
	
	set<double> S;
	S.insert(1);
	
	FOR(i,2) {
		x=0;
		FOR(y,N) {
			if(i==0 && ((X[y]<X[x]) || (X[y]==X[x] && Y[y]<Y[x]))) x=y;
			if(i==1 && ((X[y]>X[x]) || (X[y]==X[x] && Y[y]>Y[x]))) x=y;
		}
		for(double xx=0;;) {
			int ne=x;
			double mi=1e10;
			FOR(y,N) if(cr[x][y]>xx && cr[x][y]<mi) ne=y, mi=cr[x][y];
			if(mi>=1e10) break;
			S.insert(mi);
			xx=mi;
			x=ne;
		}
	}
	
	ITR(it,S) for(i=-2;i<=2;i++) val(*it+i);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
