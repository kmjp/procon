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
int A[444][444];
ll dp[404][404][404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N+1) FOR(x,N+1) cin>>A[y][x];
	FOR(i,2*N+1) {
		int y1,y2;
		FOR(y1,i+1) FOR(y2,i+1) {
			int x1=i-y1;
			int x2=i-y2;
			for(int ny1=y1;ny1<=y1+1;ny1++) {
				for(int ny2=y2;ny2<=y2+1;ny2++) {
					if(ny1==ny2) chmax(dp[i+1][ny1][ny2],dp[i][y1][y2]+A[ny1][i+1-ny1]);
					else chmax(dp[i+1][ny1][ny2],dp[i][y1][y2]+A[ny1][i+1-ny1]+A[ny2][i+1-ny2]);
				}
			}
			
		}
	}
	cout<<dp[2*N][N][N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
