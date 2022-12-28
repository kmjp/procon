#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W,SX,GX,SY,GY;
string S[2010];
int U[2010][2010];
int D[2010][2010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SY>>SX>>GY>>GX;
	SY--,GY--;
	SX--,GX--;
	FOR(y,H) cin>>S[y];
	S[H]=string(W,'#');
	H++;
	FOR(x,W) {
		FOR(y,H) {
			D[y][x]=1<<30;
			if(y) U[y][x]=U[y-1][x];
			else U[y][x]=-1;
			if(S[y][x]=='.') U[y][x]=y;
		}
	}
	deque<int> Q;
	D[SY][SX]=0;
	Q.push_back(SY*2000+SX);
	while(Q.size()) {
		int cy=Q.front()/2000;
		int cx=Q.front()%2000;
		Q.pop_front();
		int co=D[cy][cx];
		if(cy==GY&&cx==GX) {
			cout<<co<<endl;
			return;
		}
		
		for(int tx=cx-1;tx<=cx+1;tx+=2) if(tx>=0&&tx<W) {
			y=U[cy+1][tx];
			if(y<0) continue;
			if(chmin(D[y][tx],co)) Q.push_front(y*2000+tx);
			if(y<cy) {
				int hy=cy+1;
				int sy=y+(cy-y)/2+1;
				for(int tx2=tx-1;tx2<=tx+1;tx2+=2) if(tx2>=0&&tx2<W) {
					int ny=U[hy][tx2];
					if(ny>=0&&chmin(D[ny][tx2],co+1)) Q.push_back(ny*2000+tx2);
					ny=U[sy][tx2];
					if(ny>=0&&chmin(D[ny][tx2],co)) Q.push_front(ny*2000+tx2);
				}
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
