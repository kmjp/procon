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

const ll mo=998244353;

int N;
string S,T;
int dp[101010][2][2][6]; //a1, a2a2a2, a3, none

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	N+=6;
	S="www"+S+"bbb";
	T="___"+T+"___";
	int ret=1<<20;
	FOR(k,2) {
		memset(dp,0x3f,sizeof(dp));
		dp[0][0][0][5]=0;
		for(i=1;i<=N;i++) {
			if(S[i-1]=='w') {
				// take a1
				if((i==1||S[i-2]=='w')&&(i<N&&S[i]=='w')) {
					FOR(y,2) {
						dp[i][1][y][0]=min(dp[i][1][y][0],dp[i-1][0][y][0]+1);
						dp[i][1][y][0]=min(dp[i][1][y][0],dp[i-1][0][y][5]+1);
					}
				}
				// new section
				FOR(y,2) dp[i][0][y][0]=min(dp[i][0][y][0],dp[i-1][0][y][5]+1);
				FOR(x,2) FOR(y,2)	dp[i][x][y][1]=min(dp[i][x][y][1],dp[i-1][x][y][5]+1);
				FOR(x,2) dp[i][x][0][4]=min(dp[i][x][0][4],dp[i-1][x][0][5]+1);
				// keep
				FOR(x,2) FOR(y,2) FOR(j,5) dp[i][x][y][j]=min(dp[i][x][y][j],dp[i-1][x][y][j]+1);
				if(T[i-1]=='_') {
					//keep empty
					FOR(x,2) FOR(y,2) dp[i][x][y][5]=min(dp[i][x][y][5],dp[i-1][x][y][5]);
					// a1->empty
					FOR(y,2) dp[i][1][y][5]=min(dp[i][1][y][5],dp[i-1][1][y][0]);
					// a2->empty
					FOR(x,2) FOR(y,2) dp[i][x][y][5]=min(dp[i][x][y][5],dp[i-1][x][y][3]);
					// a3->empty
					FOR(x,2) dp[i][x][1][5]=min(dp[i][x][1][5],dp[i-1][x][1][4]);
				}
			}
			else {
				// take a3
				FOR(x,2) {
					dp[i][x][1][4]=min(dp[i][x][1][4],dp[i-1][x][0][4]+1);
					dp[i][x][1][4]=min(dp[i][x][1][4],dp[i-1][x][0][5]+1);
				}
				// keep
				int isL=(i>1)&&(S[i-2]=='w');
				int isR=(i<N)&&(S[i]=='w');
				FOR(x,2) FOR(y,2) {
					dp[i][x][y][0]=min(dp[i][x][y][0],dp[i-1][x][y][0]+1);
					dp[i][x][y][3]=min(dp[i][x][y][3],dp[i-1][x][y][3]+1);
					dp[i][x][y][4]=min(dp[i][x][y][4],dp[i-1][x][y][4]+1);
					dp[i][x][y][1]=min(dp[i][x][y][1],dp[i-1][x][y][1]+1); //get a2
					if(isL) dp[i][x][y][2]=min(dp[i][x][y][2],dp[i-1][x][y][1]+1); //get a2
					if(isL&&isR) dp[i][x][y][3]=min(dp[i][x][y][3],dp[i-1][x][y][1]+1); //get a2

					dp[i][x][y][1]=min(dp[i][x][y][1],dp[i-1][x][y][5]+1); //get a2
					if(isL) dp[i][x][y][2]=min(dp[i][x][y][2],dp[i-1][x][y][5]+1); //get a2
					if(isL&&isR) dp[i][x][y][3]=min(dp[i][x][y][3],dp[i-1][x][y][5]+1); //get a2

					dp[i][x][y][2]=min(dp[i][x][y][2],dp[i-1][x][y][2]+1);
					if(isR) dp[i][x][y][3]=min(dp[i][x][y][2],dp[i-1][x][y][2]+1); //get a2
					dp[i][x][y][3]=min(dp[i][x][y][3],dp[i-1][x][y][3]+1);
				}
				// new section
				FOR(y,2) dp[i][0][y][0]=min(dp[i][0][y][0],dp[i-1][0][y][5]+1);
				FOR(x,2) dp[i][x][0][4]=min(dp[i][x][0][4],dp[i-1][x][0][5]+1);
				if(T[i-1]=='_') {
					//keep empty
					FOR(x,2) FOR(y,2) dp[i][x][y][5]=min(dp[i][x][y][5],dp[i-1][x][y][5]);
					// a1->empty
					FOR(y,2) dp[i][1][y][5]=min(dp[i][1][y][5],dp[i-1][1][y][0]);
					// a2->empty
					FOR(x,2) FOR(y,2) dp[i][x][y][5]=min(dp[i][x][y][5],dp[i-1][x][y][3]);
					// a3->empty
					FOR(x,2) dp[i][x][1][5]=min(dp[i][x][1][5],dp[i-1][x][1][4]);
				}
			}
		}
		FOR(x,2) FOR(y,2) {
			ret=min(ret,dp[N][1][y][0]);
			ret=min(ret,dp[N][x][y][3]);
			ret=min(ret,dp[N][x][1][4]);
			ret=min(ret,dp[N][x][y][5]);
		}
		
		
		reverse(ALL(S));
		reverse(ALL(T));
		FORR(c,S) c='b'+'w'-c;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
