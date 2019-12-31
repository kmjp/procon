#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[1010];
int dist[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(x,1010) FOR(y,1010) dist[x][y]=10101;
	
	priority_queue<pair<int,int> > Q;
	dist[0][0]=0;
	Q.push({0,0});
	while(Q.size()) {
		auto r=Q.top();
		Q.pop();
		int cx=r.second%1000;
		int cy=r.second/1000;
		FOR(i,4) {
			int dd[4]={0,-1,0,1};
			int dx=cx+dd[i];
			int dy=cy+dd[i^1];
			if(dx<0 || dx>=W || dy<0 || dy>=H) continue;
			int cost=dist[cy][cx]+(S[cy][cx]!=S[dy][dx]);
			if(cost<dist[dy][dx]) {
				dist[dy][dx]=cost;
				Q.push({-cost,dy*1000+dx});
			}
			
		}
	}
	cout<<dist[H-1][W-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
