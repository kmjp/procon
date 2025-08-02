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

int T,K,M;
string S;
int dp[1<<20];

//第2種スターリング数の偶奇
//https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind
int stirling2_odd(ll n,ll r) {
	return ((n-r)&((r-1)/2))==0;
}

int lucas(ll N,ll K) { // C(N,K)の偶奇
	if(K<0 || K>N) return 0;
	return ((~N)&K)==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>K>>M>>S;
		// bit数
		int n=count(ALL(S),'1');
		int nl=__lg(n)+1;
		int n2=1<<nl;
		FOR(i,n2) dp[i]=0;
		FOR(i,n) dp[i]=stirling2_odd(n,i+1);
		FOR(i,nl) FOR(j,n2) if(j&(1<<i)) dp[j]^=dp[j^(1<<i)];
		
		int ret=0;
		FOR(i,min(n2,M)) if(dp[i]) {
			int num=(M-1-i)>>nl;
			if((num&1)==0) ret^=i;
			if(num%4==0) ret^=num<<nl;
			if(num%4==1) ret^=1<<nl;
			if(num%4==2) ret^=(num+1)<<nl;
		}
		/*
		//数
		for(i=1;i<=min(n,M);i++) if(stirling2_odd(n,i)) {
			for(int j=i-1;j<M;j++) if(lucas(j,i-1)) ret^=j;
		}
		*/
		cout<<ret<<endl;
	
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
