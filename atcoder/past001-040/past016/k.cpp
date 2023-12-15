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
string S[1515];
int G[1515][1515];
int SX,SY;
int L[1515][1515],R[1515][1515],U[1515][1515],D[1515][1515];
int dp[1515][1515];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) {
			if(S[y][x]=='S') {
				SX=x,SY=y;
				S[y][x]='.';
			}
			if(S[y][x]=='G') {
				G[y][x]=1;
				S[y][x]='.';
			}
		}
	}
	FOR(y,N) {
		FOR(x,N) {
			if(x&&S[y][x-1]!='X') L[y][x]=L[y][x-1]+1;
		}
		for(x=N-1;x>=0;x--) {
			if(x+1<N&&S[y][x+1]!='X') R[y][x]=R[y][x+1]+1;
		}
	}
	FOR(x,N) {
		FOR(y,N) {
			if(y&&S[y-1][x]!='X') U[y][x]=U[y-1][x]+1;
		}
		for(y=N-1;y>=0;y--) {
			if(y+1<N&&S[y+1][x]!='X') D[y][x]=D[y+1][x]+1;
		}
	}
	for(i=1;i<=N-1;i++) {
		for(y=SY%i;y<N;y+=i) {
			for(x=SX%i;x<N;x+=i) {
				dp[y][x]=1<<30;
			}
		}
		queue<int> Q;
		dp[SY][SX]=0;
		Q.push(SY*10000+SX);
		int ret=-1;
		while(Q.size()) {
			int cx=Q.front()%10000;
			int cy=Q.front()/10000;
			Q.pop();
			if(G[cy][cx]) {
				ret=dp[cy][cx];
				break;
			}
			if(L[cy][cx]>=i&&dp[cy][cx-i]==1<<30) {
				dp[cy][cx-i]=dp[cy][cx]+1;
				Q.push((cy+0)*10000+(cx-i));
			}
			if(R[cy][cx]>=i&&dp[cy][cx+i]==1<<30) {
				dp[cy][cx+i]=dp[cy][cx]+1;
				Q.push((cy+0)*10000+(cx+i));
			}
			if(U[cy][cx]>=i&&dp[cy-i][cx]==1<<30) {
				dp[cy-i][cx]=dp[cy][cx]+1;
				Q.push((cy-i)*10000+(cx+0));
			}
			if(D[cy][cx]>=i&&dp[cy+i][cx]==1<<30) {
				dp[cy+i][cx]=dp[cy][cx]+1;
				Q.push((cy+i)*10000+(cx+0));
			}
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
