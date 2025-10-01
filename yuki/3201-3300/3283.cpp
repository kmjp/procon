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

int N,X;
int P[2020];
vector<int> E[2020];
int C[2020],S[2020];
ll dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	for(i=1;i<N;i++) {
		cin>>C[i]>>S[i];
	}
	
	for(i=N-1;i>=0;i--) {
		ll from[2020];
		FOR(x,2010) from[x+1]=1LL<<60;
		from[0]=0;
		int CS=0;
		
		FORR(e,E[i]) {
			ll to[2020];
			FOR(x,2010) to[x]=1LL<<60;
			FOR(x,CS+1) FOR(y,S[e]+1) chmin(to[x+y],from[x]+dp[e][y]);
			CS+=S[e];
			swap(from,to);
		}
		
		FOR(x,2010) dp[i][x]=1LL<<60;
		dp[i][0]=0;
		FOR(x,CS+1) dp[i][x+S[i]]=min(dp[i][x+S[i]],from[x]+C[i]);
		S[i]+=CS;
	}
	ll ret=1LL<<60;
	for(x=X;x<=S[0];x++) ret=min(ret,dp[0][x]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
