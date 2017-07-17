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

int H,W,N;
string S[1010];
int X[10],Y[10];

int dist[1010][1010];

int go(int sx,int sy,int gx,int gy) {
	int x,y,i;
	FOR(y,H) FOR(x,W) dist[y][x]=10101010;
	queue<int> Q;
	dist[sy][sx]=0;
	Q.push(sy*10000+sx);
	while(Q.size()) {
		int cy=Q.front()/10000;
		int cx=Q.front()%10000;
		Q.pop();
		int co=dist[cy][cx];
		if(cy==gy && cx==gx) return co;
		
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(S[ty][tx]=='X' || dist[ty][tx]<=co+1) continue;
			dist[ty][tx]=co+1;
			Q.push(ty*10000+tx);
		}
	}
	return 110;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') X[0]=x,Y[0]=y,S[y][x]='.';
			if(S[y][x]>='1' && S[y][x]<='9') {
				j = S[y][x]-'0';
				X[j]=x;
				Y[j]=y;
				S[y][x]='.';
			}
		}
	}
	
	int ret=0;
	FOR(i,N) ret += go(X[i],Y[i],X[i+1],Y[i+1]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
