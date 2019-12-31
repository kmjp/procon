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
int A[51][51];
int C[3][51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		FOR(i,3) C[i][y][x]=1<<30;
	}
	
	priority_queue<pair<int,int>> Q;
	C[0][H-1][0]=C[1][H-1][W-1]=C[2][0][W-1]=0;
	Q.push({0,0*10000+(H-1)*100+0});
	Q.push({0,1*10000+(H-1)*100+W-1});
	Q.push({0,2*10000+0*100+W-1});
	while(Q.size()) {
		int co=-Q.top().first;
		int id=Q.top().second/10000;
		int cy=Q.top().second/100%100;
		int cx=Q.top().second%100;
		Q.pop();
		if(C[id][cy][cx]!=co) continue;
		FOR(i,4) {
			int dd[4]={0,1,0,-1};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			int nc=co+A[ty][tx];
			if(nc<C[id][ty][tx]) {
				C[id][ty][tx]=nc;
				Q.push({-nc,id*10000+ty*100+tx});
			}
		}
	}
	int mi=1<<30;
	FOR(y,H) FOR(x,W) {
		mi=min(mi,C[0][y][x]+C[1][y][x]+C[2][y][x]-2*A[y][x]);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
