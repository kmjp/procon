#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[151515];
ll dp[15151][3];
ll mo[3]={1000000007,1000000009,1000000021};
int Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(j,3) dp[0][j]=1;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]) {
			for(x=15000-A[i];x>=0;x--) {
				FOR(j,3) {
					dp[x+A[i]][j]+=dp[x][j];
					if(dp[x+A[i]][j]>=mo[j]) dp[x+A[i]][j]-=mo[j];
				}
			}
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>i>>y;
		i--;
		if(A[i]) {
			FOR(x,15000-A[i]+1) {
				FOR(j,3) {
					dp[x+A[i]][j]+=mo[j]-dp[x][j];
					if(dp[x+A[i]][j]>=mo[j]) dp[x+A[i]][j]-=mo[j];
				}
			}
		}
		A[i]=y;
		if(A[i]) {
			for(x=15000-A[i];x>=0;x--) {
				FOR(j,3) {
					dp[x+A[i]][j]+=dp[x][j];
					if(dp[x+A[i]][j]>=mo[j]) dp[x+A[i]][j]-=mo[j];
				}
			}
		}
		if(dp[K][0]||dp[K][1]||dp[K][2]) cout<<1<<endl;
		else cout<<0<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
