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

ll N;
int mat[2020][2020];


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	ll tot=0;
	FOR(x,N) FOR(y,N) {
		if(y>x && (y-x)%2) mat[x][y]=1;
		if(y<x && (y-x)%2==0) mat[x][y]=1;
	}
	if(N%2==1) {
		tot=N*(N+1)*(N-1)/24;
	}
	else {
		tot=N*(N+2)*(N-2)/24;
	}
	
	_P("%lld\n",tot);
	FOR(x,N) for(y=x+1;y<N;y++) _P("%d",mat[x][y]);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
