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

int W,H;
string S[101];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int cx,cy,dir;
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='D') dir=1,S[y][x]='.',cy=y,cx=x;
			if(S[y][x]=='U') dir=3,S[y][x]='.',cy=y,cx=x;
			if(S[y][x]=='R') dir=0,S[y][x]='.',cy=y,cx=x;
			if(S[y][x]=='L') dir=2,S[y][x]='.',cy=y,cx=x;
		}
	}
	
	int state=0,cl=0;
	FOR(i,50000) {
		if(state==0) {
			if(S[cy][cx]=='.') S[cy][cx]='+',cl++;
			state=1;
		}
		else if(state==1) {
			int ny=cy+dy[dir];
			int nx=cx+dx[dir];
			if(nx<0 || nx>=W || ny<0 || ny>=H || S[ny][nx]=='*') {
				state=2;
			}
			else {
				cy=ny;
				cx=nx;
				state=0;
			}
		}
		else if(state==2) {
			dir=(dir+1)%4;
			state=1;
		}
	}
	cout<<cl<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
