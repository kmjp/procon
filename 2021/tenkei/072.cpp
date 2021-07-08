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
string S[16];

int did[16][16];
int ma=-1;

void dfs(int y,int x,int sy,int sx, int cur) {
	if(y==sy&&x==sx&&cur>2) {
		if(cur>2) ma=max(ma,cur);
		return;
	}
	if(did[y][x]) return;
	did[y][x]=1;
	int d[]={0,1,0,-1};
	int i;
	FOR(i,4) {
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty<0||ty>=H||tx<0||tx>=W) continue;
		if(S[ty][tx]=='#') continue;
		dfs(ty,tx,sy,sx,cur+1);
		
	}
	
	did[y][x]=0;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') dfs(y,x,y,x,0);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
