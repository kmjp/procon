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
int SY,SX,GY,GX;
string S[1010];
int D[1010][1010][6];

int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};
int to[4][6]={
	{1,5,2,0,4,3}, //l
	{4,1,0,3,5,2}, //u
	{3,0,2,5,4,1}, //r
	{2,1,5,3,0,4}, //d
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>SY>>SX;
	cin>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) FOR(i,6) D[y][x][i]=1<<30;
	queue<int> Q;
	D[SY][SX][0]=0;
	Q.push(SY*1000+SX);
	while(Q.size()) {
		int cy=Q.front()%1000000/1000;
		int cx=Q.front()%1000;
		int ct=Q.front()/1000000;
		Q.pop();
		if(cy==GY&&cx==GX&&ct==0) {
			cout<<D[cy][cx][ct]<<endl;
			return;
		}
		FOR(i,4) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			int tt=to[i][ct];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			if(D[ty][tx][tt]>D[cy][cx][ct]+1) {
				D[ty][tx][tt]=D[cy][cx][ct]+1;
				Q.push(ty*1000+tx+tt*1000000);
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
