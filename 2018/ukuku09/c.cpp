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

int H,W,Q;
string S[30];
int dp[900][900];

vector<int> from[900];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,900) FOR(x,900) dp[y][x]=1<<30;
	
	
	
	cin>>H>>W>>Q;
	FOR(y,H) cin>>S[y];
	queue<int> PQ;
	FOR(y,H) FOR(x,W) if(S[y][x]!='#') {
		dp[y*30+x][y*30+x]=0;
		PQ.push((y*30+x)*900+(y*30+x));
		if(S[y-1][x]=='.'||S[y-1][x]=='v') from[y*30+x].push_back(y*30+x-30);
		if(S[y+1][x]=='.'||S[y+1][x]=='^') from[y*30+x].push_back(y*30+x+30);
		if(S[y][x-1]=='.'||S[y][x-1]=='>') from[y*30+x].push_back(y*30+x-1);
		if(S[y][x+1]=='.'||S[y][x+1]=='<') from[y*30+x].push_back(y*30+x+1);
		if(S[y][x]=='.'||(S[y][x]=='v'&&S[y+1][x]=='#')||(S[y][x]=='^'&&S[y-1][x]=='#')||(S[y][x]=='>'&&S[y][x+1]=='#')||(S[y][x]=='<'&&S[y][x-1]=='#')) from[y*30+x].push_back(y*30+x);
	}
	
	while(PQ.size()) {
		x=PQ.front()/900;
		y=PQ.front()%900;
		PQ.pop();
		FORR(s,from[x]) FORR(t,from[y]) if(dp[s][t]>dp[x][y]+1) {
			dp[s][t]=dp[x][y]+1;
			PQ.push(s*900+t);
		}
	}
	FOR(i,Q) {
		int SX,SY,GX,GY;
		cin>>SX>>SY>>GX>>GY;
		SX--,SY--,GX--,GY--;
		if(dp[SY*30+SX][GY*30+GX]>1<<20) {
			cout<<-1<<endl;
		}
		else {
			cout<<dp[SY*30+SX][GY*30+GX]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
