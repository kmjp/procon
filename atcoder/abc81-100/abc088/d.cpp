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

int H,W;
string S[101];
int D[101][101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int num=0;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			D[y][x]=101010;
			if(S[y][x]=='.') num++;
		}
	}
	queue<int> Q;
	D[0][0]=0;
	Q.push(0);
	while(Q.size()) {
		int cy=Q.front()/100;
		int cx=Q.front()%100;
		Q.pop();
		
		int d[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0 || ty>=H || tx<0|| tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			if(D[ty][tx]<=D[cy][cx]+1) continue;
			D[ty][tx]=D[cy][cx]+1;
			Q.push(ty*100+tx);
		}
	}
	
	if(D[H-1][W-1]>=100000) return _P("-1\n");
	else _P("%d\n",num-D[H-1][W-1]-1);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
