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

void update(int y,int x) {
	if(S[y][x]=='.') S[y][x]='#';
}

void dfs(int sy,int sx) {
	int dd[4]={1,0,-1,0};
	int i;
	FOR(i,4) {
		int tx=sx+dd[i];
		int ty=sy+dd[i^1];
		if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
		if(S[ty][tx]=='#') {
			S[ty][tx]='.';
			dfs(ty,tx);
			return;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int ty,tx;
	FOR(y,H) {
		cin>>S[y];
		if(y==0 || y==H-1) {
			FOR(x,W) update(y,x);
		}
		else if(y%4==1) {
			update(y,0);
			update(y,W-1);
		}
		else if(y%4==3) {
			update(y,W-3);
			update(y,W-1);
		}
		else {
			FOR(x,W-2) update(y,x);
			update(y,W-1);
		}
		FOR(x,W) if(S[y][x]=='@') ty=y,tx=x;
	}
	
	dfs(ty,tx);
	FOR(y,H) cout<<S[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
