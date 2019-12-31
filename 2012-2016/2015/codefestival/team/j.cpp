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

int memo[101][101];

int win(int X,int Y) {
	if(X>Y) swap(X,Y);
	if(X==0) return 0;
	
	if(memo[X][Y]==-1) {
		memo[X][Y]=0;
		for(int i=1;i<=X-1;i++) if(win(X-i,Y)==0) memo[X][Y]=1;
		for(int i=1;i<=min(X,Y-1);i++) if(win(X,Y-i)==0) memo[X][Y]=1;
		//if(memo[X][Y]==0) _P("%d %d %d\n",X,Y,memo[X][Y]);
	}
	return memo[X][Y];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>x>>y;
	if(x>y) swap(x,y);
	if(x==1 && y%2==1) return _P("rng\n");
	if(x==2 && y%4==2) return _P("rng\n");
	if(x==3 && y%4==0 && y>=8) return _P("rng\n");
	if(x==4 && y==4) return _P("rng\n");
	
	_P("snuke\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
