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

int T;
ll N;

int D[20];

int dp[20][40][11];

int ok(int num) {
	ZERO(dp);
	dp[0][0][num]=1;
	int d;
	FOR(d,19) {
		int c,n;
		for(n=num;n>=0;n--) {
			FOR(c,40) if(dp[d][c][n]) {
				if(n) dp[d][c][n-1]=1;
				
				for(int p=c+n*1;p<=c+n*3;p++) {
					if(D[d]!=p%10) continue;
					int nc=p/10;
					dp[d+1][nc][n]=1;
				}
				
			}
		}
	}
	return dp[19][0][0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(i,20) {
			D[i]=N%10;
			N/=10;
		}
		
		for(i=1;i<=10;i++) {
			if(ok(i)) {
				cout<<i<<endl;
				break;
			}
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
