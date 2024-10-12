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
int vis[6][6];
ll ret;

void dfs(int cy,int cx) {
	if(cy==GY&&cx==GX) {
		ret++;
		return;
	}
	int dy[4]={0,0,1,-1};
	int dx[4]={1,-1,0,0};
	vis[cy][cx]=1;
	int i,j;
	FOR(i,4) {
		int ty=cy+dy[i];
		int tx=cx+dx[i];
		if(ty<0||ty>=H||tx<0||tx>=W) continue;
		if(vis[ty][tx]) continue;
		FOR(j,4) {
			int ty2=ty+dy[j];
			int tx2=tx+dx[j];
			if(ty2<0||ty2>=H||tx2<0||tx2>=W) continue;
			if(ty2==cy&&tx2==cx) continue;
			if(vis[ty2][tx2]) break;
		}
		if(j==4) dfs(ty,tx);
	}
	vis[cy][cx]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	dfs(SY,SX);
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
