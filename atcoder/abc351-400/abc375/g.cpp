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
int A[202020],B[202020],C[202020];
vector<pair<int,int>> E[202020];
ll dp[202020][2],pat[202020][2];
ll same[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		E[A[i]].push_back({B[i],C[i]});
		E[B[i]].push_back({A[i],C[i]});
		same[i]=1;
	}
	
	vector<ll> mos={1000000007,1000000009,998244353};
	FORR(mo,mos) {
		FOR(i,N) {
			dp[i][0]=dp[i][1]=1LL<<60;
			pat[i][0]=pat[i][1]=0;
		}
		dp[0][0]=dp[N-1][1]=0;
		pat[0][0]=1;
		pat[N-1][1]=1;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,0});
		Q.push({0,2*N-1});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second%N;
			int id=Q.top().second/N;
			Q.pop();
			if(dp[cur][id]!=co) continue;
			FORR2(e,c,E[cur]) {
				int up=0;
				if(chmin(dp[e][id],co+c)) pat[e][id]=0, up=1;
				if(dp[e][id]==co+c) (pat[e][id]+=pat[cur][id])%=mo;
				if(up) Q.push({-dp[e][id],id*N+e});
			}
		}
		ll mi=dp[N-1][0];
		FOR(i,M) {
			if(mi==dp[A[i]][0]+C[i]+dp[B[i]][1]) {
				if(pat[N-1][0]==pat[A[i]][0]*pat[B[i]][1]%mo) same[i]=0;
			}
			if(mi==dp[A[i]][1]+C[i]+dp[B[i]][0]) {
				if(pat[N-1][0]==pat[B[i]][0]*pat[A[i]][1]%mo) same[i]=0;
			}
		}
	}
	FOR(i,M) {
		if(same[i]) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
