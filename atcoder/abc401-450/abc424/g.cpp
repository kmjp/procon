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

int N,M;
int A[101];
int num[101];
ll dp[111][10101];
int B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M+1) {
		FOR(j,N) num[i]+=min(i,A[j]);
	}
	
	FOR(j,101) FOR(k,10101) dp[j][k]=-1LL<<50;
	FOR(k,10101) dp[0][k]=0;
	
	vector<pair<int,int>> V;
	FOR(i,M) {
		cin>>B>>C;
		V.push_back({B,C});
	}
	sort(ALL(V));
	reverse(ALL(V));
	ll ret=0;
	int sum=0;
	FORR2(b,c,V) {
		sum+=b;
		for(i=M;i>=0;i--) for(j=b;j<=min(sum,num[i+1]);j++) {
			chmax(dp[i+1][j],dp[i][j-b]+c);
			chmax(ret,dp[i+1][j]);
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
