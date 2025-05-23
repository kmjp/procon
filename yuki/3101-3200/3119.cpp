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
int A[202020];
ll pm[202020];

const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll dp[202020][4];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	pm[0]=1;
	FOR(i,N) {
		cin>>A[i];
		pm[i+1]=pm[i]*M%mo;
	}
	dp[0][0]=min(A[0],A[1]);
	dp[0][1]=max(A[0],A[1])-min(A[0],A[1]);
	dp[0][2]=M-max(A[0],A[1]);
	
	ll ret=(M-A[0])*pm[N-1]%mo;
	for(i=1;i<N;i++) {
		ll X[4]={0,min(A[i],A[i-1]),max(A[i],A[i-1]),M};
		ll Y[4]={0,min(A[i],A[i+1]),max(A[i],A[i+1]),M};
		
		FOR(x,3) FOR(y,3) {
			if(A[i-1]<A[i]) {
				//swap‚·‚é‚Æ1‰ñ‰ñ”‚ª‘‚¦‚é
				if(y==1&&x!=y) {
					ll num=X[y+1]-X[y];
					(dp[i][3]+=dp[i-1][x]*num)%=mo;
					(ret+=dp[i-1][x]*num%mo*pm[N-1-i])%=mo;
				}
				else {
					FOR(k,3) {
						ll num=max(0LL,min(X[y+1],Y[k+1])-max(X[y],Y[k]));
						(dp[i][k]+=dp[i-1][x]*num)%=mo;
						if(y==2) (ret+=dp[i-1][x]*num%mo*pm[N-1-i])%=mo;
					}
				}
			}
			else {
				//swap‚·‚é‚Æ1E2‰ñ‰ñ”‚ª‘‚¦‚é
				if(x==1&&y!=x) {
					ll num=X[y+1]-X[y];
					(dp[i][3]+=dp[i-1][x]*num)%=mo;
					(ret+=dp[i-1][x]*num%mo*pm[N-1-i]*((y+2)/2))%=mo;
				}
				else {
					FOR(k,3) {
						ll num=max(0LL,min(X[y+1],Y[k+1])-max(X[y],Y[k]));
						(dp[i][k]+=dp[i-1][x]*num)%=mo;
						if(y!=0) (ret+=dp[i-1][x]*num%mo*pm[N-1-i])%=mo;
					}
				}
			}
		}
		
		
		//‚à‚¤swapŽg—pÏ‚Ý‚Ìê‡
		(ret+=dp[i-1][3]*(M-A[i])%mo*pm[N-1-i])%=mo;
		(dp[i][3]+=dp[i-1][3]*M)%=mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
