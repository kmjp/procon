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
int A[2020];
int S[2020];
const ll mo=998244353;
vector<int> V;

ll dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A[x-1]++;
	}
	
	FOR(i,N) for(j=1;j<=N;j++) S[j]+=min(j,A[i]);
	
	dp[0][0]=1;
	for(i=N;i>=1;i--) {
		for(x=N;x>=0;x--) {
			ll a=0;
			for(k=0;x+k*i<=N;k++) {
				if(x-k>=0) {
					if(N-x<=S[i]) (a+=dp[x][k])%=mo;
					dp[x][k]=0;
				}
				(dp[x+k][k]+=a)%=mo;
				if(N-(x+k)>S[i-1]) dp[x+k][k]=0;
			}
		}
	}
	ll ret=0;
	FOR(i,N+1) ret+=dp[N][i];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
