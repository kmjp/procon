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

ll H,W,T;
string S[1010];
int sy,sx,gy,gx;

bool ok(ll X) {
	ll dist[100][100];
	int y,x,i,cx,cy;
	
	FOR(x,H*W) FOR(y,H*W) dist[x][y]=1LL<<60;
	FOR(x,H*W) dist[x][x]=0;
	FOR(y,H) FOR(x,W) {
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=y+dd[i],tx=x+dd[i^1];
			if(tx<0 || ty<0 || tx>=W || ty>=H) continue;
			dist[y*W+x][ty*W+tx]=(S[ty][tx]=='#')?X:1;
		}
	}
	FOR(i,H*W) FOR(x,H*W) FOR(y,H*W) dist[x][y]=min(dist[x][y],dist[x][i]+dist[i][y]);
	
	return dist[sy*W+sx][gy*W+gx]<=T;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>T;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='S') S[y][x]='.', sy=y,sx=x;
		FOR(x,W) if(S[y][x]=='G') S[y][x]='.', gy=y,gx=x;
	}
	ll ret=0;
	for(i=40;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
