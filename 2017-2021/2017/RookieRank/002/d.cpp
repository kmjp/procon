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

int N;

int hoge(int N,int a,int b) {
	int dist[25][25];
	int x,y,i;
	FOR(x,N) FOR(y,N) dist[x][y]=25*25*25;
	dist[0][0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cy=Q.front()/100;
		int cx=Q.front()%100;
		Q.pop();
		int dx[8]={a,b,-a,-b,a,b,-a,-b};
		int dy[8]={b,a,b,a,-b,-a,-b,-a};
		
		FOR(i,8) {
			y=cy+dy[i];
			x=cx+dx[i];
			if(x<0|| x>=N || y<0 || y>=N) continue;
			if(dist[y][x]>dist[cy][cx]+1) {
				dist[y][x]=dist[cy][cx]+1;
				Q.push(y*100+x);
			}
		}
	}
	if(dist[N-1][N-1]>=25*25*25) return -1;
	return dist[N-1][N-1];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N-1;i++) {
		for(j=1;j<=N-1;j++) _P("%d%c",hoge(N,i,j),(j==N-1)?'\n':' ');
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
