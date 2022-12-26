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
string T[505];
int L;
string S;
int Q;
int X[505][505][31],Y[505][505][31];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) cin>>T[y];
	cin>>S;
	L=S.size();
	FOR(y,H) FOR(x,W) if(T[y][x]=='.') {
		int cy=y;
		int cx=x;
		FORR(c,S) {
			if(c=='L' && cx&&T[cy][cx-1]=='.') cx--;
			if(c=='R' && cx+1<W&&T[cy][cx+1]=='.') cx++;
			if(c=='U' && cy&&T[cy-1][cx]=='.') cy--;
			if(c=='D' && cy+1<H&&T[cy+1][cx]=='.') cy++;
		}
		X[y][x][0]=cx;
		Y[y][x][0]=cy;
	}
	
	FOR(i,30) {
		FOR(y,H) FOR(x,W) if(T[y][x]=='.') {
			int cy,cx;
			cx=X[y][x][i];
			cy=Y[y][x][i];
			X[y][x][i+1]=X[cy][cx][i];
			Y[y][x][i+1]=Y[cy][cx][i];
			
		}
	}
	
	while(Q--) {
		cin>>y>>x>>r;
		int cy=y-1,cx=x-1;
		FOR(i,30) if((r/L)&(1<<i)) {
			x=X[cy][cx][i];
			y=Y[cy][cx][i];
			cy=y;
			cx=x;
		}
		FOR(i,r%L) {
			if(S[i]=='L' && cx&&T[cy][cx-1]=='.') cx--;
			if(S[i]=='R' && cx+1<W&&T[cy][cx+1]=='.') cx++;
			if(S[i]=='U' && cy&&T[cy-1][cx]=='.') cy--;
			if(S[i]=='D' && cy+1<H&&T[cy+1][cx]=='.') cy++;
		}
		cout<<cy+1<<" "<<cx+1<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
