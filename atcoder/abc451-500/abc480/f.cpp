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
ll A[22],S[22];

ll dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	ll V=S[N]/M;
	int mask;
	FOR(mask,1<<N) dp[mask]=1LL<<60;
	dp[0]=0;
	FOR(mask,1<<N) {
		ll sum=0;
		FOR(i,N) if(mask&(1<<i)) sum+=A[i];
		FOR(i,N) if((mask&(1<<i))==0) {
			ll nsum=sum+A[i];
			ll dif;
			if(sum%V==0&&nsum%V==0) dif=A[i]/V-1;
			if(sum%V==0&&nsum%V) dif=A[i]/V;
			if(sum%V&&nsum%V==0) dif=A[i]/V;
			if(sum%V&&nsum%V) dif=nsum/V-sum/V;
			chmin(dp[mask|(1<<i)],dp[mask]+dif);
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
