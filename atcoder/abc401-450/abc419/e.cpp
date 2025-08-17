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

int N,M,L;
int A[504];
int C[505][505];
ll dp[505][505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,N) {
		cin>>A[i];
		FOR(x,M) {
			if(x>=A[i]) C[i%L][x]+=x-A[i];
			else C[i%L][x]+=M+x-A[i];
		}
	}
	
	FOR(x,505) FOR(y,505) dp[x][y]=1LL<<60;
	dp[0][0]=0;
	FOR(i,L) {
		FOR(x,M) FOR(y,M) dp[i+1][(x+y)%M]=min(dp[i+1][(x+y)%M],dp[i][x]+C[i][y]);
	}
	cout<<dp[L][0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
