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


int N,X,Y;
string S[500];
int D[505][505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,500) S[i]=string(500,'.');
	FOR(i,N) {
		cin>>x>>y;
		S[y+250][x+250]='#';
	}
	FOR(x,500) FOR(y,500) D[y][x]=1<<20;
	queue<int> Q;
	D[250][250]=0;
	Q.push(250*500+250);
	while(Q.size()) {
		int cy=Q.front()/500;
		int cx=Q.front()%500;
		Q.pop();
		if(cy==Y+250&&cx==X+250) {
			cout<<D[cy][cx]<<endl;
			return;
		}
		int dy[6]={1,1,1,0,0,-1};
		int dx[6]={1,0,-1,1,-1,0};
		FOR(i,6) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0 || ty>=500 || tx<0 || tx>=500 || S[ty][tx]=='#') continue;
			if(D[ty][tx]>1+D[cy][cx]) {
				D[ty][tx]=1+D[cy][cx];
				Q.push(ty*500+tx);
			}
		}
		
		
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
