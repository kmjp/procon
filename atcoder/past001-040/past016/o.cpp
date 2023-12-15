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

int N,K,Q;
ll P[101];
const ll mo=998244353;
ll C[11][202020];
ll B[11];
ll ret[202020];
ll add[11][202020];
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) cin>>ret[i];
	FOR(i,K) cin>>P[i];
	
	FOR(i,K) C[i][i]=1;
	for(i=K;i<=N;i++) {
		FOR(j,K) {
			FOR(x,K) (C[j][i]+=C[j][i-(x+1)]*P[x])%=mo;
		}
	}
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		FOR(i,K) cin>>B[i];
		if(R-L<=K) {
			FOR(i,R-L) (ret[L+i]+=B[i])%=mo;
		}
		else {
			FOR(i,K) {
				(ret[L+i]+=B[i])%=mo;
				(add[i][L+K]+=B[i])%=mo;
				ll sum=0;
				FOR(j,K) (sum+=C[j][R-L-K+i]*B[j])%=mo;
				add[i][R]+=mo-sum;
			}
		}
	}
	FOR(i,N) {
		if(i>=K) {
			FOR(j,K) (dp[i-K+j]+=add[j][i])%=mo;
			FOR(j,K) (dp[i]+=dp[i-(j+1)]*P[j])%=mo;
		}
		(ret[i]+=dp[i])%=mo;
		cout<<ret[i]<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
