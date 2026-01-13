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

int N;
string S[1010];
int dp[1010][1010][4];
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};

int dfs(int cy,int cx,int id) {
	if(dp[cy][cx][id]!=-1) return dp[cy][cx][id];
	if(cy==1&&cx==1) return 1;
	dp[cy][cx][id]=0;
	
	int ty=cy+dy[id];
	int tx=cx+dx[id];
	if(S[ty][tx]=='.') {
		dp[cy][cx][id]=dfs(ty,tx,id);
	}
	else {
		dp[cy][cx][id]=dfs(cy,cx,(id+1)%4);
	}
	
	return dp[cy][cx][id];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[y];
	
	int ret=0;
	MINUS(dp);
	FOR(y,N) FOR(x,N) FOR(i,4) if(S[y][x]=='.') {
		int num=0;
		FOR(i,4) num+=dfs(y,x,i);
		if(num) ret++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
