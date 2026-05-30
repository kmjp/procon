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


int H,W;
char fc[1010][1010][4];
int from[1010][1010][4];
string S[1010];

int SX,SY,GX,GY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(from);
	cin>>H>>W;
	queue<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') {
				from[y][x][0]=1<<30;
				from[y][x][1]=1<<30;
				from[y][x][2]=1<<30;
				from[y][x][3]=1<<30;
				Q.push(y*W*4+x*4+0);
				Q.push(y*W*4+x*4+1);
				Q.push(y*W*4+x*4+2);
				Q.push(y*W*4+x*4+3);
				S[y][x]='.';
				SY=y;
				SX=x;
			}
			if(S[y][x]=='G') {
				GX=x,GY=y;
				S[y][x]='.';
			}
		}
	}
	while(Q.size()) {
		int state=Q.front();
		int cy=Q.front()/4/W;
		int cx=Q.front()/4%W;
		int dir=Q.front()%4;
		Q.pop();
		int dy[4]={0,1,0,-1};
		int dx[4]={1,0,-1,0};
		
		if(cy==GY&&cx==GX) {
			string ret;
			while(cy!=SY||cx!=SX) {
				state=from[cy][cx][dir];
				ret+="RDLU"[dir];
				cy=state/4/W;
				cx=state/4%W;
				dir=state%4;
			}
			reverse(ALL(ret));
			cout<<"Yes"<<endl;
			cout<<ret<<endl;
			return;
		}
		
		
		FOR(i,4) {
			if(S[cy][cx]=='o'&&i!=dir) continue;
			if(S[cy][cx]=='x'&&i==dir) continue;
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			if(from[ty][tx][i]==-1) {
				from[ty][tx][i]=state;
				Q.push(ty*4*W+tx*4+i);
			}
		}
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
