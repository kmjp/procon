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
int SY,SX;
int GY,GX;
int dist[100][100];
string S[100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>SY>>SX;
	cin>>GY>>GX;
	SY--,SX--;
	GY--,GX--;
	
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) dist[y][x]=101010;
	queue<int> Q;
	dist[SY][SX]=0;
	Q.push(100*SY+SX);
	while(Q.size()) {
		y=Q.front()/100;
		x=Q.front()%100;
		Q.pop();
		FOR(i,4) {
			int dd[]={1,0,-1,0};
			int ty=y+dd[i];
			int tx=x+dd[i^1];
			if(S[ty][tx]=='.' && dist[ty][tx]> dist[y][x]+1) {
				dist[ty][tx]=dist[y][x]+1;
				Q.push(ty*100+tx);
			}
		}
	}
	cout<<dist[GY][GX]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
