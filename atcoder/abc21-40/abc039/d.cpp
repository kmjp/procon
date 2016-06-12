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
string S[101];
string T[101];
string G[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int dx,dy;
	cin>>H>>W;
	FOR(y,H) cin>>S[y], T[y]=G[y]=S[y];
	FOR(y,H) FOR(x,W) T[y][x]='#', G[y][x]='.';
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		for(dx=-1;dx<=1;dx++) for(dy=-1;dy<=1;dy++) {
			int ty=y+dy;
			int tx=x+dx;
			if(ty>=0 && ty<H && tx>=0 && tx<W) T[ty][tx]='.';
		}
	}
	
	FOR(y,H) FOR(x,W) if(T[y][x]=='#') {
		for(dx=-1;dx<=1;dx++) for(dy=-1;dy<=1;dy++) {
			int ty=y+dy;
			int tx=x+dx;
			if(ty>=0 && ty<H && tx>=0 && tx<W) G[ty][tx]='#';
		}
	}
	int ng=0;
	FOR(y,H) if(S[y]!=G[y]) return _P("impossible\n");
	cout<<"possible"<<endl;
	FOR(y,H) cout<<T[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
