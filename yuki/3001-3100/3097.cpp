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

int N,M,K;
ll A[10];

ll dp[2020][1<<9];
vector<ll> P[1<<9],MA[9][1<<9];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int mask;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	FOR(mask,1<<N) FOR(i,N) if((mask&(1<<i))==0) dp[0][mask]+=A[i];
	//カット対象のmaskの遷移先に対するフローの移動量
	FOR(mask,1<<N) for(int sm=mask;sm>=0;sm--) sm&=mask, P[mask].push_back(K*(__builtin_popcount(mask)-__builtin_popcount(sm)));
	
	//維持不可な頂点とカット対象のmaskの遷移先に対する遷移先
	FOR(i,N) FOR(mask,1<<N) for(int sm=mask;sm>=0;sm--) {
		sm&=mask;
		int tar=mask;
		tar|=(sm<<1)|(sm>>(N-1));
		tar|=(sm>>1)|(sm<<(N-1));
		tar^=tar&(1<<i);
		tar&=(1<<N)-1;
		MA[i][mask].push_back(tar);
	}
	
	FOR(i,M) {
		cin>>x;
		x--;
		FOR(mask,1<<N) dp[i+1][mask]=1LL<<60;
		FOR(mask,1<<N) FOR(j,P[mask].size()) chmin(dp[i+1][MA[x][mask][j]],dp[i][mask]+P[mask][j]);
		
		cout<<dp[i+1][0]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
