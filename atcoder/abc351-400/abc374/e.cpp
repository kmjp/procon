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

int N,X;
ll A[101],P[101],B[101],Q[101];

ll dp[101][1012010];

ll ok(ll v) {
	int i;
	ll sum=0;
	
	FOR(i,N) {
		ll num=max(v/(A[i]*B[i])-100,0LL);
		
		sum+=num*dp[i][A[i]*B[i]];
		sum+=dp[i][v-num*A[i]*B[i]];
	}
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>A[i]>>P[i]>>B[i]>>Q[i];
		if(A[i]*Q[i]<B[i]*P[i]) swap(A[i],B[i]),swap(P[i],Q[i]);
		
		dp[i][0]=0;
		FOR(j,1011000) dp[i][j+1]=1LL<<60;
		FOR(j,1011000) {
			chmin(dp[i][j+A[i]],dp[i][j]+P[i]);
			chmin(dp[i][j+B[i]],dp[i][j]+Q[i]);
		}
		for(j=1010000;j>=0;j--) chmin(dp[i][j],dp[i][j+1]);
	}
	
	ll ret=0;
	for(i=30;i>=0;i--) if(ok(ret+(1LL<<i))<=X) ret+=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
