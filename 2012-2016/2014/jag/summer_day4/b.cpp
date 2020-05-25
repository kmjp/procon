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
string S[52];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	S[0]=S[H+1]=string(52,'#');
	FOR(y,H) {
		cin>>s;
		S[y+1]="#"+s+"#";
	}
	H+=2;
	W+=2;
	
	int dir;
	int dy[4]={0,1,0,-1};
	int dx[4]={1,0,-1,0};
	int cy,cx;
	FOR(y,H) FOR(x,W) {
		if(S[y][x]=='>') cy=y,cx=x,dir=0;
		if(S[y][x]=='v') cy=y,cx=x,dir=1;
		if(S[y][x]=='<') cy=y,cx=x,dir=2;
		if(S[y][x]=='^') cy=y,cx=x,dir=3;
	}
	S[cy][cx]='+';
	int now=1;
	FOR(i,20000) {
		if(S[cy][cx]=='G') {
			cout<<now+1<<endl;
			return;
		}
		if(S[cy][cx]=='.') {
			now++;
			S[cy][cx]='+';
		}
		if(S[cy+dy[dir]][cx+dx[dir]]=='#') {
			dir=(dir+3)%4;
		}
		else if(S[cy+dy[dir]+dy[(dir+1)%4]][cx+dx[dir]+dx[(dir+1)%4]]=='#') {
			cy+=dy[dir];
			cx+=dx[dir];
		}
		else {
			if(S[cy+dy[dir]][cx+dx[dir]]=='.') {
				S[cy+dy[dir]][cx+dx[dir]]='+';
				now++;
			}
			if(S[cy+dy[dir]][cx+dx[dir]]=='G') {
				cout<<now+1<<endl;
				return;
			}
			cy+=dy[dir]+dy[(dir+1)%4];
			cx+=dx[dir]+dx[(dir+1)%4];
			dir=(dir+1)%4;
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
