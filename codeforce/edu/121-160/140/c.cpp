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
int A[101][101];
const ll mo=998244353;
ll dp[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		for(j=i;j<N;j++) cin>>A[i+1][j+1];
	}
	ll ret=2;
	FOR(i,N) if(A[i+1][i+1]==2) ret=0;
	dp[1][0]=ret;
	for(i=1;i<N;i++) {
		FOR(x,i) if(dp[i][x]) {
			// same
			for(y=0;y<=i;y++) {
				if(A[y][i+1]==1&&x>=y) break;
				if(A[y][i+1]==2&&x<y) break;
			}
			if(y==i+1) (dp[i+1][x]+=dp[i][x])%=mo;
			// dif
			for(y=0;y<=i;y++) {
				if(A[y][i+1]==1) break;
			}
			if(y==i+1) (dp[i+1][i]+=dp[i][x])%=mo;
		}
	}
	ret=0;
	FOR(i,N+1) ret+=dp[N][i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
