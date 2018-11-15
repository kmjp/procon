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
string S[1010];
int SY,SX,GY,GX;

int D[1010][1010];
int D2[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>X;
	queue<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') SY=y,SX=x,S[y][x]='.';
			if(S[y][x]=='G') GY=y,GX=x,S[y][x]='.';
			if(S[y][x]=='@') {
				D[y][x]=X;
				Q.push(y*1000+x);
			}
			else if(S[y][x]=='#') {
				D[y][x]=10101010;
			}
			else {
				D[y][x]=-1;
			}
			D2[y][x]=1010101;
		}
	}
	
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		int d[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			
			if(D[ty][tx]<D[cy][cx]-1) {
				D[ty][tx]=D[cy][cx]-1;
				if(D[ty][tx]>0) Q.push(ty*1000+tx);
			}
		}
	}
	
	D2[SY][SX]=0;
	Q.push(SY*1000+SX);
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		int d[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			
			if(D[ty][tx]<0 && D2[ty][tx]>D2[cy][cx]+1) {
				D2[ty][tx]=D2[cy][cx]+1;
				Q.push(ty*1000+tx);
			}
		}
	}
	
	if(D2[GY][GX]<1010000) cout<<D2[GY][GX]<<endl;
	else cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
