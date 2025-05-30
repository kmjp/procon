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
ll A[20][20];
ll ret=-1;
int vis[20][20];
void dfs(int y,int x) {
	if(x>=W) {
		dfs(y+1,0);
		return;
	}
	if(y>=H) {
		ll sum=0;;
		int i,j;
		FOR(i,H) FOR(j,W) if(vis[i][j]==0) sum^=A[i][j];
		ret=max(ret,sum);
		return;
	}
	
	dfs(y,x+1);
	if(vis[y][x]==0) {
		if(x+1<W&&vis[y][x+1]==0) {
			vis[y][x]=vis[y][x+1]=1;
			dfs(y,x+1);
			vis[y][x]=vis[y][x+1]=0;
		}
		if(y+1<H&&vis[y+1][x]==0) {
			vis[y][x]=vis[y+1][x]=1;
			dfs(y,x+1);
			vis[y][x]=vis[y+1][x]=0;
		}
		
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	dfs(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
