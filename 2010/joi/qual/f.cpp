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
int N;
int A[10][10];

int ret;

void dfs(int y,int x,int mask) {
	int cn=A[y][x]-2;
	
	if(cn==-1) {
		ret += (mask==(1<<N)-1);
		return;
	}
	
	mask |= 1<<cn;
	A[y][x]=0;
	int cx,cy;
	for(cx=x+1;cx<W && A[y][cx]>=0;cx++)  if(A[y][cx]>0) {dfs(y,cx,mask); if(A[y][cx]!=1) break;}
	for(cx=x-1;cx>=0 && A[y][cx]>=0;cx--) if(A[y][cx]>0) {dfs(y,cx,mask); if(A[y][cx]!=1) break;}
	for(cy=y+1;cy<H && A[cy][x]>=0;cy++)  if(A[cy][x]>0) {dfs(cy,x,mask); if(A[cy][x]!=1) break;}
	for(cy=y-1;cy>=0 && A[cy][x]>=0;cy--) if(A[cy][x]>0) {dfs(cy,x,mask); if(A[cy][x]!=1) break;}
	A[y][x]=cn+2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	N=0;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		if(A[y][x]==2) {
			A[y][x]=1;
		}
		else if(A[y][x]==1) {
			A[y][x]=1+(++N);
		}
	}
	
	FOR(y,H) FOR(x,W) if(A[y][x]==1) {
		int cx,cy;
		for(cx=x+1;cx<W && A[y][cx]>=0;cx++)  if(A[y][cx]>0) {dfs(y,cx,0); break;}
		for(cx=x-1;cx>=0 && A[y][cx]>=0;cx--) if(A[y][cx]>0) {dfs(y,cx,0); break;}
		for(cy=y+1;cy<H && A[cy][x]>=0;cy++)  if(A[cy][x]>0) {dfs(cy,x,0); break;}
		for(cy=y-1;cy>=0 && A[cy][x]>=0;cy--) if(A[cy][x]>0) {dfs(cy,x,0); break;}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
