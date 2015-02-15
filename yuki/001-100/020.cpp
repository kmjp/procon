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

int N,V,OX,OY;
int L[201][201];
int H[201][201][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V>>OX>>OY;
	OX--,OY--;
	FOR(y,N) FOR(x,N) cin>>L[y][x];
	MINUS(H);
	H[0][0][1]=V;
	priority_queue<pair<int,int> > Q;
	Q.push(make_pair(V,1000000));
	while(Q.size()) {
		int k=Q.top().second;
		Q.pop();
		int cx=k%1000,cy=k/1000%1000,cz=k/1000000;
		
		FOR(i,4) {
			int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
			int tx=cx+dx[i],ty=cy+dy[i];
			if(tx<0 || ty<0 || tx>=N || ty>=N) continue;
			x=H[cy][cx][cz]-L[ty][tx];
			if(x<=0) continue;
			if(H[ty][tx][cz]<x) {
				H[ty][tx][cz]=x;
				Q.push(make_pair(x,cz*1000000+ty*1000+tx));
			}
			if(ty==OY && tx==OX && cz && H[ty][tx][0]<x*2) {
				H[ty][tx][0]=x*2;
				Q.push(make_pair(x*2,ty*1000+tx));
			}
		}
	}
	
	if(H[N-1][N-1][0]>=0 || H[N-1][N-1][1]>=0) _P("YES\n");
	else _P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
