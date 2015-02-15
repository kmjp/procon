#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,V,SX,SY,GX,GY;
int L[101][101];
int HP[2][101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V>>SX>>SY>>GX>>GY;
	FOR(y,N) FOR(x,N) cin>>L[y][x];
	
	SX--,SY--,GX--,GY--;
	HP[0][SY][SX]=V;
	FOR(i,10001) {
		int cur=i%2,tar=cur^1;
		ZERO(HP[tar]);
		j=0;
		FOR(y,N) FOR(x,N) if(HP[cur][y][x]>0) {
			j++;
			FOR(k,4) {
				int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
				int tx=x+dx[k],ty=y+dy[k];
				if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
				if(HP[cur][y][x]>L[ty][tx]) HP[tar][ty][tx]=max(HP[tar][ty][tx],HP[cur][y][x]-L[ty][tx]);
			}
		}
		if(HP[tar][GY][GX]>0) return _P("%d\n",i+1);
	}
	return _P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
