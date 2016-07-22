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

int D[303][303];
int N;

void hoge(int y,int x,int dir,int cur) {
	D[y][x]=cur++;
	int dy[4]={0,1,0,-1};
	int dx[4]={1,0,-1,0};
	if(cur==N*N+1) return;
	
	if(y+dy[dir]<0 || y+dy[dir]>=N || x+dx[dir]<0 || x+dx[dir]>=N || D[y+dy[dir]][x+dx[dir]]>0) dir++;
	dir%=4;
	hoge(y+dy[dir],x+dx[dir],dir,cur);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hoge(0,0,0,1);
	
	FOR(y,N) FOR(x,N) _P("%03d%c",D[y][x],(x==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
