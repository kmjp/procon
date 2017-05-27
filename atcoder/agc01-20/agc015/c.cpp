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

int H,W,Q;
string S[2020];
int X1[202020],Y1[202020],X2[202020],Y2[202020];
int ret[202020];

int st[2020][2020];
int dep[2020][2020];
int SS[2020][2020];
int vis[2020][2020];

void dfs(int cy,int cx,int d) {
	// left
	int ty,tx;
	vis[cy][cx]=1;
	dep[cy][cx]=d;
	ty=cy,tx=cx-1;
	if(tx>=0 && S[ty][tx]=='1' && vis[ty][tx]==0) dfs(ty,tx,d+1);
	ty=cy,tx=cx+1;
	if(tx<W && S[ty][tx]=='1' && vis[ty][tx]==0) dfs(ty,tx,d+1);
	ty=cy-1,tx=cx;
	if(ty>=0 && S[ty][tx]=='1' && vis[ty][tx]==0) dfs(ty,tx,d+1);
	ty=cy+1,tx=cx;
	if(ty<H && S[ty][tx]=='1' && vis[ty][tx]==0) dfs(ty,tx,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) cin>>S[y];
	
	FOR(i,Q) {
		cin>>Y1[i]>>X1[i]>>Y2[i]>>X2[i];
		X1[i]--;
		Y1[i]--;
		X2[i]--;
		Y2[i]--;
		
	}
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='1' && vis[y][x]==0) {
		vis[y][x]=1;
		st[y][x]++;
		dfs(y,x,2);
	}
	FOR(y,H+1) FOR(x,W+1) SS[y+1][x+1]=SS[y+1][x]+SS[y][x+1]+st[y][x]-SS[y][x];
	
	
	FOR(i,Q) {
		r=SS[Y2[i]+1][X2[i]+1]+SS[Y1[i]][X1[i]]-SS[Y2[i]+1][X1[i]]-SS[Y1[i]][X2[i]+1];
		for(y=Y1[i];y<=Y2[i];y++) {
			if(X1[i]>0 && dep[y][X1[i]]==dep[y][X1[i]-1]+1) r++;
			if(X2[i]<W && dep[y][X2[i]]==dep[y][X2[i]+1]+1) r++;
		}
		for(x=X1[i];x<=X2[i];x++) {
			if(Y1[i]>0 && dep[Y1[i]][x]==dep[Y1[i]-1][x]+1) r++;
			if(Y2[i]<H && dep[Y2[i]][x]==dep[Y2[i]+1][x]+1) r++;
		}
		
		_P("%d\n",r);
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
