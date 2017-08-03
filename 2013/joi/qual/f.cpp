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

int H,W,K;
string S[51];
int memo[51][51][4][1<<12];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int pat[1<<12];
int num;

int dfs(int Y,int X,int K,int log) {
	if(memo[Y][X][K][log]!=-1) return memo[Y][X][K][log];
	int ret=-30000;
	int cur=0;
	int plog=(log<<2)&((1<<12)-1);
	int i;
	
	if(S[Y][X]>='1' && S[Y][X]<='9' && pat[log]==1) cur=S[Y][X]-'0';
	
	if(Y==H-1 && X==W-1) ret=cur;
	
	FOR(i,4) {
		int ty=Y+dy[i];
		int tx=X+dx[i];
		if(i>=2 && K==0) break;
		if(ty<0 || ty>=H || tx<0 || tx>=W || S[ty][tx]=='#') continue;
		ret=max(ret,cur+dfs(ty,tx,K-(i>=2),plog+i));
	}
	return memo[Y][X][K][log]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1<<12) {
		pat[i]=1;
		y=x=0;
		int cur=i;
		FOR(j,6) {
			y-=dy[cur&3];
			x-=dx[cur&3];
			if(x==0 && y==0) pat[i]=0;
			cur>>=2;
		}
	}
	
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	MINUS(memo);
	
	cout<<dfs(0,0,K,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
