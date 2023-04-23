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
ll dp[4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) c-='0';
	reverse(ALL(S));
	ll pat=1;
	FOR(i,N-1) pat=pat*2%mo;
	
	ll ret=0;
	ll p2=1;
	FOR(i,N) {
		ZERO(dp);
		dp[0]=1;
		dp[1]=mo-1;
		FOR(j,N) {
			if(j) (dp[j]+=dp[j-1])%=mo;
			ll a=dp[j];
			(dp[j+1]+=a)%=mo;
			if(i+j<N&&S[i+j]==1) (dp[j+i+1]+=mo-a)%=mo;
		}
		
		(dp[N]+=dp[N-1])%=mo;
		ret+=(pat-dp[N]+mo)*p2%mo;
		p2=p2*2%mo;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
