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
ll mo;
int L[3030];
ll dp[6030][6030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=3000;i++) {
		L[i]=1+to_string(i).size();
	}
	
	cin>>N>>mo;
	for(i=1;i<=N;i++) {
		(dp[i][L[i]]+=26)%=mo;
		(dp[i+1][L[i]]+=mo-26)%=mo;
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=2*i;j++) {
			// 1-9
			(dp[i][j]+=dp[i-1][j])%=mo;
			ll a=25*dp[i][j]%mo;
			(dp[i+1][j+2]+=a)%=mo;
			(dp[i+10][j+2]+=mo-a)%=mo;
			(dp[i+10][j+3]+=a)%=mo;
			(dp[i+100][j+3]+=mo-a)%=mo;
			(dp[i+100][j+4]+=a)%=mo;
			(dp[i+1000][j+4]+=mo-a)%=mo;
			(dp[i+1000][j+5]+=a)%=mo;
			(dp[i+3001][j+5]+=mo-a)%=mo;
		}
	}
	ll ret=0;
	FOR(j,N) ret+=dp[N][j];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
