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

int N;
int H,W;
string S[19];
int A[20][20];
int mi;

void dfs(int mask,int y,int x,int num) {
	int dy[8]={0,1,1,1,0,-1,-1,-1};
	int dx[8]={1,1,0,-1,-1,-1,0,1};
	int i;
	FOR(i,8) {
		int j;
		int del=0;
		for(j=1;j<=20;j++) {
			int ty=y+dy[i]*j;
			int tx=x+dx[i]*j;
			if(j>=2&&ty>H-1) {
				mi=min(mi,num+1);
				return;
			}
			if(ty<0 || tx<0 || tx>=W) {
				j=-1;
				break;
			}
			if(j>=2&&ty>=H-1) {
				mi=min(mi,num+1);
				return;
			}
			if(A[ty][tx]==-1 || (mask&(1<<A[ty][tx]))==0) break;
			del |= (1<<A[ty][tx]);
		}
		if(j==-1 || del==0) continue;
		dfs(mask^del,y+dy[i]*j,x+dx[i]*j,num+1);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int sy,sx;
	MINUS(A);
	H=19,W=15;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='O') {
				sy=y,sx=x;
			}
			if(S[y][x]=='X') {
				A[y][x]=N++;
			}
		}
	}
	mi=101010;
	dfs((1<<N)-1,sy,sx,0);
	if(mi>100) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
