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

int N,X,Y,Z;
int pat[16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>Z;
	X--,Y--,Z--;
	
	FOR(y,N) FOR(x,N) {
		int tx=x%4,ty=y%4;
		if((tx%3==0)^(ty%3==0)) pat[y][x]=N*N-(y*N+x+1);
		else pat[y][x]=y*N+x;
	}
	
	int xorv=Z^pat[Y][X];
	FOR(y,N) FOR(x,N) _P("%d%c",(pat[y][x]^xorv)+1,(x==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
