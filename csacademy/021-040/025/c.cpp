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
int A[1010][1010];
int S[1010][1010];

int ok[1010][1010];

int BH,BW;
int SY,SX,GY,GX;
int dist[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x]+A[y][x];
		dist[y][x]=1010101;
	}
	cin>>BH>>BW>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	
	FOR(y,H-BH+1) FOR(x,W-BW+1) ok[y][x]=(S[y+BH][x+BW]-S[y][x+BW]-S[y+BH][x]+S[y][x])==0;
	if(ok[SY][SX]==0) return _P("-1\n");
	
	queue<int> Q;
	dist[SY][SX]=0;
	Q.push(SY*10000+SX);
	while(Q.size()) {
		int cy=Q.front()/10000;
		int cx=Q.front()%10000;
		Q.pop();
		
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(tx<0 || ty<0 || ok[ty][tx]==0) continue;
			if(dist[ty][tx]>dist[cy][cx]+1) {
				dist[ty][tx]=dist[cy][cx]+1;
				Q.push(ty*10000+tx);
			}
		}
	}
	
	if(dist[GY][GX]>=101000) dist[GY][GX]=-1;
	cout<<dist[GY][GX]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
