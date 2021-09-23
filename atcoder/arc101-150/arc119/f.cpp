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


int N,K;
string S;
const ll mo=1000000007;
int dp[4040][4040][5][2];

void go(int i,int nx,int ny,int nz,int x,int y,int z) {
	if(nx>ny+2) nx=ny+2;
	if(ny>nx+2) ny=nx+2;
	(dp[i+1][nx][ny-nx+2][nz]+=dp[i][x][y-x+2][z])%=mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	dp[0][0][2][0]=1;
	FOR(i,N) {
		FOR(x,N) for(y=max(0,x-2);y<=x+2;y++) {
			if(S[i]=='A'||S[i]=='?') {
				go(i,x+1,y,0,x,y,0);
				go(i,min(x,y)+1,min(x+2,y),0,x,y,1);
			}
			if(S[i]=='B'||S[i]=='?') {
				go(i,x,y+1,1,x,y,1);
				go(i,min(x,y+2),min(x,y)+1,1,x,y,0);
			}
		}
	}
	
	ll ret=0;
	FOR(x,N) FOR(y,5) if(x<K||(x+y-2)<K) ret+=dp[N-1][x][y][0]+dp[N-1][x][y][1];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
