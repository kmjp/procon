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
string S,T;
int A[202020];
int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	int X=S.size();
	int Y=T.size();
	for(i=0;i*X<=200000;i++) dp[i*X]=i;
	for(i=0;i+Y<=200000;i++) dp[i+Y]=max(dp[i+Y],dp[i]);
	
	FOR(i,N) {
		cin>>A[i];
		FOR(j,dp[A[i]]) cout<<S<<" ";
		FOR(j,(A[i]-dp[A[i]]*X)/Y) cout<<T<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
