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
ll E[40];
int dp[1<<20];

void dfs(int L,int R,int d) {
	if(d==0) return;
	int M=(R+L)/2;
	dfs(L,M,d-1);
	dfs(M,R,d-1);
	int i;
	FOR(i,M-L) {
		int a=dp[L+i], b=dp[M+i];
		dp[L+i]=a+b;
		dp[M+i]=a+(R-M)-b;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x] |= 1LL<<y;
		E[y] |= 1LL<<x;
	}
	int mask;
	
	FOR(mask,1<<20) {
		int num=0;
		FOR(y,20) FOR(x,y) if(E[x+20]&(1LL<<(y+20))) if(mask&((1<<x)|(1<<y))) num^=1;
		dp[mask]=num;
	}
	
	dfs(0,1<<20,20);
	
	ll ret=0;
	FOR(mask,1<<20) {
		int num=0;
		int cut=((1<<20)-1)^mask;
		FOR(y,20) FOR(x,y) if(E[x]&(1<<y)) if(mask&((1<<x)|(1<<y))) num^=1;
		FOR(x,20) if(mask&(1<<x)) FOR(y,20) if(E[x]&(1LL<<(y+20))) num^=1;
		
		int Tmask=0;
		FOR(i,20) if(__builtin_popcountll(cut&E[i+20])%2==1) Tmask |= 1<<i;
		
		if(num==0) ret+=(1<<20)-dp[Tmask];
		else ret+=dp[Tmask];
	}
	
	assert((ret&((1LL<<(40-N))-1))==0);
	
	ret>>=(40-N);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
