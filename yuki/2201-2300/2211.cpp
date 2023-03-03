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

int N,M,C[202020];

ll dp[202020];
ll p2[202020];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		C[x]++;
	}
	for(i=M;i>=1;i--) {
		int num=0;
		for(j=i;j<=M;j+=i) num+=C[j];
		dp[i]=p2[num]-1;
		for(j=2*i;j<=M;j+=i) dp[i]+=mo-dp[j];
		dp[i]%=mo;
	}
	
	FOR(i,M) cout<<dp[i+1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
