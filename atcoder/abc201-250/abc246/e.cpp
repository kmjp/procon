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


int N;
int AY,AX,BY,BX;
string S[2020];

int dy[4]={1,1,-1,-1};
int dx[4]={1,-1,1,-1};

int D[2020][2020][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>AY>>AX>>BY>>BX;
	AY--,AX--,BY--,BX--;
	FOR(y,N) cin>>S[y];
	
	FOR(y,N) FOR(x,N) FOR(i,4) D[y][x][i]=1<<30;
	deque<int> Q;
	FOR(i,4) {
		D[AY][AX][i]=1;
		Q.push_back(AY*20000+AX*10+i);
	}
	while(Q.size()) {
		int cy=Q.front()/20000;
		int cx=Q.front()/10%2000;
		int dir=Q.front()%10;
		Q.pop_front();
		if(cy==BY&&cx==BX) {
			cout<<D[cy][cx][dir]<<endl;
			return;
		}
		
		FOR(i,4) if(D[cy][cx][i]>D[cy][cx][dir]+1) {
			D[cy][cx][i]=D[cy][cx][dir]+1;
			Q.push_back(cy*20000+cx*10+i);
		}
		int ty=cy+dy[dir];
		int tx=cx+dx[dir];
		if(ty>=0&&ty<N&&tx>=0&&tx<N&&S[ty][tx]=='.'&&D[ty][tx][dir]>D[cy][cx][dir]) {
			D[ty][tx][dir]=D[cy][cx][dir];
			Q.push_front(ty*20000+tx*10+dir);
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
