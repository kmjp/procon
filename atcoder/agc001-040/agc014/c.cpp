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

int H,W,K;
string S[808];
int SY,SX;

int dist[808][808];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') {
				S[y][x]='.';
				SY=y;
				SX=x;
			}
			dist[y][x]=1<<20;
		}
	}
	
	dist[SY][SX]=0;
	queue<int> Q;
	Q.push(SY*1000+SX);
	int mi=1<<20;
	
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		
		mi=min(mi,1+(cy+K-1)/K);
		mi=min(mi,1+(cx+K-1)/K);
		mi=min(mi,1+((H-1-cy)+K-1)/K);
		mi=min(mi,1+((W-1-cx)+K-1)/K);
		if(dist[cy][cx]==K) continue;
		
		FOR(i,4) {
			int dd[]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || tx<0 || ty>=H || tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			if(dist[ty][tx]>dist[cy][cx]+1) {
				dist[ty][tx]=dist[cy][cx]+1;
				Q.push(ty*1000+tx);
			}
		}
	}
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
