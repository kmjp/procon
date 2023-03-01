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
string S;
int P[5050][5050];
int dp[5050];
int ok(int v) {
	ZERO(dp);
	dp[0]=1;
	int i,j;
	FOR(i,N) if(dp[i]) {
		for(j=i+v;j<=N;j++) if(P[i][j]) dp[j]=1;
	}
	return dp[N];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) P[i][i]=P[i][i+1]=1;
	for(l=2;l<=N;l++) {
		for(i=0;i+l<=N;i++) {
			P[i][i+l]=(P[i+1][i+l-1]&&S[i]==S[i+l-1]);
		}
	}
	int ret=0;
	for(i=15;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
