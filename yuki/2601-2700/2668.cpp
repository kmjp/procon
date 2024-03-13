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

ll N;
ll mo;

ll dp[10101010][2][2];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	
	dp[0][0][1]=1;
	for(i=1;i<10001010;i++) {
		//Ô¨ŽlŠp¨Ô
		dp[i][1][0]+=dp[i-1][1][0];
		//Ô¨ŽlŠp¨”’
		dp[i][0][1]+=i*dp[i-1][1][0];
		//”’¨ŽlŠp¨”’
		dp[i][0][1]+=i*dp[i-1][0][0]%mo*(i-1);
		//”’¨ŽlŠp¨Ô
		dp[i][1][0]+=dp[i-1][0][0]%mo*(i-1);

		//Ô¨”’
		dp[i][0][0]+=dp[i-1][1][0];
		//”’¨”’
		dp[i][0][0]+=dp[i-1][0][0];
		dp[i][0][1]+=dp[i-1][0][1];
		//”’¨Ô
		dp[i][1][0]+=dp[i-1][0][1];
		
		dp[i][0][0]%=mo;
		dp[i][1][0]%=mo;
		dp[i][0][1]%=mo;
		dp[i][1][1]%=mo;
	}
	
	ll p2=0,p3=0;
	
	ll ret=1;
	
	for(i=2;i<N;i++) {
		(ret*=(dp[i*2-1][0][0]+dp[i*2-1][1][0]))%=mo;
	}
	for(i=1;i<=2*N-1;i++) ret=ret*i%mo;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
