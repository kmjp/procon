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

int H,W,X;
int SX,SY,GX,GY;
ll A[505][505];
ll C[505050];
ll dist[505][505];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>X;
	cin>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(y,H) FOR(x,W) cin>>A[y][x], dist[y][x]=1LL<<60;
	for(i=1;i<=X;i++) cin>>C[i];
	
	dist[SY][SX]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,SY*1000+SX});
	
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/1000;
		int cx=Q.top().second%1000;
		Q.pop();
		if(dist[cy][cx]!=co) continue;
		
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			
			if(A[cy][cx]==A[ty][tx]) {
				if(dist[ty][tx]>co) {
					dist[ty][tx]=co;
					Q.push({-co,ty*1000+tx});
				}
			}
			else {
				if(dist[ty][tx]>co+C[A[ty][tx]]) {
					dist[ty][tx]=co+C[A[ty][tx]];
					Q.push({-dist[ty][tx],ty*1000+tx});
				}
			}
		}
		
	}
	
	cout<<dist[GY][GX]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
