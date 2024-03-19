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
const ll mo=998244353;

int num[22],pat[22];
ll dp[1<<20][22];
ll fact[1<<21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=1<<20;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>N;
	FOR(i,N) {
		FOR(j,i+1) num[i]+=1<<(N-1-j);
		pat[i]=1<<(N-1-i);
	}
	num[N]=1<<N;
	pat[N]=1;
	
	dp[0][0]=1<<(N-1);
	cout<<0<<endl;
	for(i=1;i<(1<<N);i++) {
		FOR(j,N) {
			//same
			if(num[j]>i) (dp[i][j]+=dp[i-1][j]*(num[j]-i))%=mo;
			// new
			(dp[i][j+1]+=dp[i-1][j]*pat[j+1])%=mo;
		}
		ll a=dp[i][N]*fact[(1<<N)-1-i]%mo;
		a=a*(1<<N)%mo;
		cout<<a<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
