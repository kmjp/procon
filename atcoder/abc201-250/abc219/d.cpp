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

int N,X,Y;
int A[303],B[303];

int dp[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(x,303) FOR(y,303) dp[x][y]=1<<20;
	dp[0][0]=0;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		for(x=X;x>=0;x--) {
			for(y=Y;y>=0;y--) dp[min(X,x+A[i])][min(Y,y+B[i])]=min(dp[min(X,x+A[i])][min(Y,y+B[i])],dp[x][y]+1);
		}
	}
	
	if(dp[X][Y]>300) dp[X][Y]=-1;
	cout<<dp[X][Y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
