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

int I,H,O;
ll X[101];
ll W[101][101];
ll h[101];
ll U[101][101];
ll h2[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>I>>H>>O;
	FOR(i,I) cin>>X[i];
	FOR(y,H) FOR(x,I) cin>>W[y][x];
	FOR(y,H) FOR(x,I) h[y] += W[y][x]*X[x];
	FOR(y,H) if(h[y]<0) h[y]=0;
	FOR(y,O) FOR(x,H) cin>>U[y][x];
	FOR(y,O) FOR(x,H) h2[y] += U[y][x]*h[x];
	FOR(y,O) cout<<h2[y]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
