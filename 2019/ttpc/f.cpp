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

int N,M;
int W,X,Y,Z;
vector<pair<int,int>> E[101010];
vector<pair<int,int>> RE[101010];
ll dist[101010][3];
ll rdist[101010][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>W>>X>>Y>>Z;
	W--,X--,Y--,Z--;
	
	FOR(i,M) {
		cin>>r>>x>>y;
		E[x-1].push_back({y-1,r});
		RE[y-1].push_back({x-1,r});
		
	}
	
	FOR(i,N) dist[i][0]=dist[i][1]=dist[i][2]=rdist[i][0]=rdist[i][1]=1LL<<60;
	rdist[W][0]=rdist[Y][1]=dist[X][0]=dist[Z][1]=0;
	for(i=N-1;i>=0;i--) {
		FORR(e,E[i]) {
			dist[i][0]=min(dist[i][0],dist[e.first][0]+e.second);
			dist[i][1]=min(dist[i][1],dist[e.first][1]+e.second);
			dist[i][2]=min(dist[i][2],dist[e.first][2]+e.second);
		}
		dist[i][2]=min(dist[i][2],dist[i][0]+dist[i][1]);
		
	}
	ll mi=1LL<<60;
	FOR(i,N) {
		FORR(e,RE[i]) {
			rdist[i][0]=min(rdist[i][0],rdist[e.first][0]+e.second);
			rdist[i][1]=min(rdist[i][1],rdist[e.first][1]+e.second);
		}
		mi=min(mi,rdist[i][0]+rdist[i][1]+dist[i][2]);
	}
	mi=min(mi,dist[W][0]+dist[Y][1]);
	
	if(mi>=1LL<<60) {
		cout<<"Impossible"<<endl;
	}
	else {
		cout<<mi<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
