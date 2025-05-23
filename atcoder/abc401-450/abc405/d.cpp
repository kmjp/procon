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
string S[1010];
int dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	queue<int> Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='E') {
				dp[y][x]=0;
				Q.push(y*1000+x);
			}
			else {
				dp[y][x]=1<<30;
			}
		}
	}
	
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		int dy[]={0,1,0,-1};
		int dx[]={1,0,-1,0};
		string V="<^>v";
		
		FOR(i,4) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#'||dp[ty][tx]<1<<20) continue;
			dp[ty][tx]=dp[cy][cx]+1;
			S[ty][tx]=V[i];
			Q.push(ty*1000+tx);
		}
		
		
	}
	FOR(y,H) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
