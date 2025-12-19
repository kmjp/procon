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
vector<pair<int,int>> P[27];
string S[1010];
int pat[1010][1010];
int dp[1010][1010];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]>='a'&&S[y][x]<='z') {
				P[S[y][x]-'a'].push_back({y,x});
				pat[y][x]=S[y][x]-'a';
				S[y][x]='.';
			}
			else {
				pat[y][x]=26;
			}
			dp[y][x]=1LL<<30;
		}
	}
	dp[0][0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		if(cy==H-1&&cx==W-1) {
			cout<<dp[cy][cx]<<endl;
			return;
		}
		FORR2(ty,tx,P[pat[cy][cx]]) if(chmin(dp[ty][tx],dp[cy][cx]+1)) Q.push(ty*1000+tx);
		P[pat[cy][cx]].clear();
		FOR(i,4) {
			int d[]={1,0,-1,0};
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			if(chmin(dp[ty][tx],dp[cy][cx]+1)) Q.push(ty*1000+tx);
		}
		
		
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
