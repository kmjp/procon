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

int N,P[10101],A[10101],B[10101],S[10101];

int dp[10101][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1001) dp[N][i]=i;
	FOR(i,N) {
		cin>>P[i]>>A[i]>>B[i];
		S[i+1]=S[i]+B[i];
	}
	for(i=N-1;i>=0;i--) {
		FOR(j,1001) {
			if(P[i]>=j) dp[i][j]=dp[i+1][j+A[i]];
			else dp[i][j]=dp[i+1][max(j-B[i],0)];
		}
	}
	
	int Q,X;
	cin>>Q;
	while(Q--) {
		cin>>X;
		if(X<=1000) {
			cout<<dp[0][X]<<endl;
		}
		else if(X-S[N]>1000) {
			cout<<X-S[N]<<endl;
		}
		else {
			x=lower_bound(S,S+N,X-1000)-S;
			cout<<dp[x][X-S[x]]<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
