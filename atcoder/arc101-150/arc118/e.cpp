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
int A[205],P[205];
const ll mo=998244353;

ll dp[205][205][205][2][2];
ll fact[205];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	FOR(i,201) fact[i+1]=fact[i]*(i+1)%mo;
	
	cin>>N;
	int lef=N;
	FOR(i,N) {
		cin>>A[i+1];
		if(A[i+1]>=0) {
			P[A[i+1]]=1;
			lef--;
		}
	}
	
	dp[0][0][0][0][0]=1;
	
	FOR(x,N+2) FOR(y,N+2) {
		if(x>=1&&x<=N&&A[x]==y) continue;
		FOR(i,N+2) {
			// take block
			if(A[x]==-1&&P[y]==0&&(y>=1&&y<=N)) (dp[x][y][i+1][1][1]+=dp[x][y][i][0][0])%=mo;
			FOR(j,2) FOR(k,2) {
				// row
				(dp[x+1][y][i][0][k]+=dp[x][y][i][j][k])%=mo;
				// col
				(dp[x][y+1][i][j][0]+=dp[x][y][i][j][k])%=mo;
			}
		}
	}
	
	
	ll ret=0;
	FOR(i,lef+1) {
		if(i%2==0) {
			(ret+=fact[lef-i]*dp[N+1][N+1][i][0][0])%=mo;
		}
		else {
			(ret-=fact[lef-i]*dp[N+1][N+1][i][0][0])%=mo;
		}
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
