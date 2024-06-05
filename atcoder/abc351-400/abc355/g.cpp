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

int N,K;
int P[50505];
ll PS[50505];
ll PL[50505];
ll PR[50505];
ll dp[50505];

ll lambda;

ll costL(int L,int R) {
	return (PL[R]-PL[L])-(PS[R]-PS[L])*(L);
}
ll costR(int L,int R) {
	return (PR[R]-PR[max(0,L-1)])-(PS[R]-PS[max(0,L-1)])*(N-R+1);
}

ll cost(int L,int R) {
	assert(L<R);
	if(L==0&&R==N+1) return 1LL<<60;
	if(L==0) return costR(L,R)+lambda;
	if(R==N+1) return costL(L,R)+lambda;
	int M=(L+R)/2;
	return costL(L,M)+costR(M+1,R)+lambda;
	
}

void dfs2(int le,int ri,int p1,int p2) {
	if(le+1>=ri) return;
	int mi=(le+ri)/2;
	int p3=p1;
	ll v=1LL<<60;
	for(int i=p1;i<=min(mi-1,p2);i++) if(chmin(v,dp[i]+cost(i,mi))) p3=i;
	dp[mi]=min(dp[mi],v);
	dfs2(le,mi,p1,p3);
	dfs2(mi,ri,p3,p2);
}

void dfs(int le,int ri) {
	if(le+1>=ri) return;
	int mi=(le+ri)/2;
	dfs(le,mi);
	ll p1=le,v1=1LL<<60;
	ll p2=le,v2=1LL<<60;
	for(int i=le;i<mi;i++) {
		if(chmin(v1,dp[i]+cost(i,mi))) p1=i;
		if(chmin(v2,dp[i]+cost(i,ri-1))) p2=i;
	}
	dp[mi]=min(dp[mi],v1);
	dp[ri-1]=min(dp[ri-1],v2);
	dfs2(mi,ri-1,p1,p2);
	
	dfs(mi,ri);
}

ll hoge(ll v) {
	lambda=v;
	int i;
	FOR(i,N+2) dp[i]=1LL<<60;
	dp[0]=0;
	dfs(0,N+2);
	return dp[N+1]-v*(K+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N+1) {
		if(i!=N) cin>>P[i];
		PS[i+1]=PS[i]+P[i];
		PL[i+1]=PL[i]+1LL*(i+1)*P[i];
		PR[i+1]=PR[i]+1LL*(N-i)*P[i];
	}
	
	ll CL=0,CR=1LL<<35;
	ll mi=max(hoge(CL),hoge(CR));
	while(CR-CL>=3) {
		ll M1=(CL*2+CR)/3;
		ll M2=(CL+CR*2)/3;
		ll V1=hoge(M1);
		ll V2=hoge(M2);
		if(V1>V2) CR=M2;
		else if(V2>V1) CL=M1;
		else CL=M1,CR=M2;
		mi=max({mi,V1,V2});
	}
	for(ll a=CL;a<=CR;a++) mi=max(mi,hoge(a));
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
