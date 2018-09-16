#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int H,W;
string S[100];
int dist[100][100];
int sy,sx,gy,gx;

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W;
	cin>>sy>>sx>>gy>>gx;
	FOR(y,H) cin>>S[y];
	
	FOR(y,100) FOR(x,100) dist[y][x]=100000;
	dist[sy-1][sx-1]=0;
	queue<int> Q;
	Q.push((sy-1)*1000+(sx-1));
	
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		int cy=k/1000,cx=k%1000;
		FOR(i,4) {
			int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
			int tx=cx+dx[i],ty=cy+dy[i];
			if(S[ty][tx]=='#') continue;
			if(dist[ty][tx]<=dist[cy][cx]+1) continue;
			dist[ty][tx]=dist[cy][cx]+1;
			Q.push(ty*1000+tx);
		}
	}
	_P("%d\n",dist[gy-1][gx-1]);
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


