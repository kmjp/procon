#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int C[500][500];

ll D[500][500][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>y>>x>>r;
		C[y-1][x-1]=r;
	}
	FOR(y,N) FOR(x,N) FOR(i,2) D[y][x][i]=1LL<<60;
	D[0][0][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/500%500;
		int cx=Q.top().second%500;
		int turn=Q.top().second/500/500;
		Q.pop();
		if(D[cy][cx][turn]!=co) continue;
		
		if(cy==N-1&&cx==N-1) {
			cout<<co<<endl;
			return;
		}
		co++;
		int d[]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(tx<0||ty<0||tx>=N||ty>=N) continue;
			if(D[ty][tx][turn]>co+C[ty][tx]) {
				D[ty][tx][turn]=co+C[ty][tx];
				Q.push({-D[ty][tx][turn],turn*500*500+ty*500+tx});
			}
			if(turn==0&&D[ty][tx][1]>co) {
				D[ty][tx][1]=co;
				Q.push({-D[ty][tx][1],1*500*500+ty*500+tx});
			}
			
			
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
