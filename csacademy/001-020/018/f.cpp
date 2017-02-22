#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[201010];
int G[201010][21];
int Gp[201010],Gv[201010];

ll dp[202020];
ll S[202020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], A[N+i]=G[i][0]=G[i+N][0]=A[i];
	FOR(i,20) {
		FOR(x,2*N) {
			if(x-(1<<i)<0) G[x][i+1]=1;
			else G[x][i+1]=__gcd(G[x][i],G[x-(1<<i)][i]);
		}
	}
	FOR(i,N) {
		Gp[i]=i+1;
		for(j=19;j>=0;j--) if(Gp[i]&&__gcd(Gv[i],G[Gp[i]-1][j])>1) Gv[i] = __gcd(Gv[i],G[Gp[i]-1][j]), Gp[i]-=1<<j;
	}
	
	ll ret=0;
	
	if(Gp[N-1]==0) {
		ret=1;
		FOR(i,N) ret=ret*2%mo;
		ret = (ret+(mo-N))%mo;
	}
	else {
		int cur=0;
		FOR(i,N) {
			x = __gcd(cur,A[(N-i)%N]);
			if(x==1) break;
			if(cur!=x) {
				cur = x;
				dp[0]=S[0]=1;
				dp[1]=1,S[1]=2;
				for(j=1;j<N-i;j++) {
					if(Gp[j]==0 && __gcd(Gv[j],cur)==1) Gp[j]=1;
					dp[j+1]=S[j];
					if(Gp[j]>=1) dp[j+1]+=mo-S[Gp[j]-1];
					dp[j+1]%=mo;
					S[j+1]=(S[j]+dp[j+1])%mo;
					//_P("%d/%d : %lld %lld\n",j,Gp[j],dp[j+1],S[j+1]);
				}
			}
			//_P("%d %lld : %d %d\n",i,dp[N-i],cur,x);
			(ret += dp[N-i])%=mo;
		}
	}
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
