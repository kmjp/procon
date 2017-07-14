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
int A[101][101];
int vis[101][101];
int ma;

void dfs(int y,int x,int dep) {
	if(y<0 || y>=H || x<0 || x>=W) return;
	if(A[y][x]==0) return;
	if(vis[y][x]) return;
	dep++;
	ma=max(ma,dep);
	vis[y][x]=1;
	dfs(y-1,x,dep);
	dfs(y+1,x,dep);
	dfs(y,x-1,dep);
	dfs(y,x+1,dep);
	vis[y][x]=0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	FOR(y,H) FOR(x,W) dfs(y,x,0);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
