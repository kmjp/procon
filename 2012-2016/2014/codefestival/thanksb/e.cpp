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

int H,W,N;
int sy,sx,gy,gx;
char S[100][100];
int vis[100][100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>sy>>sx>>gy>>gx;
	sy--,sx--,gy--,gx--;
	
	cin>>N;
	while(N--) {
		cin>>y>>x>>k>>l;
		FOR(i,k) FOR(j,l) S[y-1+i][x-1+j]=1;
	}
	
	if(S[sy][sx]==0) return _P("NO\n");
	
	
	vis[sy][sx]=1;
	queue<int> Q;
	Q.push(sy*100+sx);
	while(Q.size()) {
		k=Q.front();
		int cy=k/100,cx=k%100;
		Q.pop();
		FOR(i,4) {
			int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
			int ty=cy+dy[i],tx=cx+dx[i];
			if(tx<0 || ty<0 || ty>=H || tx>=W) continue;
			if(S[ty][tx]==0 || vis[ty][tx]) continue;
			if(gy==ty && tx==gx) return _P("YES\n");
			vis[ty][tx]=1;
			Q.push(ty*100+tx);
		}
	}
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
