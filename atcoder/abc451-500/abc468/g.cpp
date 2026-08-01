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
const ll mo=998244353;
ll dp[2020][2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[1][1]=1;
	for(i=2;i<=2000;i++) dp[2][i]=2;
	
	for(i=3;i<=2010;i++) {
		dp[i][i]=dp[i-1][i];
		//”‚ð‘‚â‚³‚È‚¢
		for(j=i+1;j<=2000;j++) {
			(dp[i][j]+=dp[i-1][j]*(j-i+1))%=mo;
		}
		ll sum=dp[i-1][i];
		//”‚ð‘‚â‚·
		for(j=i+1;j<=2000;j++) {
			(dp[i][j]+=sum*2)%=mo;
			(sum+=dp[i-1][j])%=mo;
		}
		
	}
	
	
	cin>>N>>S;
	if(S[0]=='x'||S[N-1]=='x') {
		cout<<0<<endl;
		return;
	}
	vector<int> V;
	int pre=0;
	ll ret=1;
	for(i=1;i<N;i++) if(S[i]=='o') {
		ret=ret*dp[i-pre+1][i-pre+1]%mo;
		pre=i;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
