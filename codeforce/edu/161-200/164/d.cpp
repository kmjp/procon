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

int N,A[5050];
const ll mo=998244353;

ll dp[5050];
ll p2[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,5010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	
	//‘S•”‚ð”‚¦‚é
	dp[0]=1;
	ll ret=0;
	FOR(i,N) {
		(ret+=p2[N-1]*(A[i]/2))%=mo;
		for(j=N;j>=0;j--) (dp[j+A[i]%2]+=dp[j])%=mo;
	}
	FOR(i,N+1) (ret+=dp[i]*((i+1)/2))%=mo;
	
	//‰ß”¼”‚É‚È‚é‚à‚Ì
	ZERO(dp);
	dp[0]=1;
	FOR(i,N) {
		FOR(j,A[i]) {
			(ret+=mo-dp[j]*((A[i]+j+1)/2))%=mo;
			(ret+=dp[j]*A[i])%=mo;
		}
		for(j=5000;j>=0;j--) if(j+A[i]<=5000) (dp[j+A[i]]+=dp[j])%=mo;
		
	}
	
	
	
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
