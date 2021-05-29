#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int E[17];
ll F[1<<17];
ll G[1<<17];
ll p2[500];

const ll mo=998244353;


void dfs(int cur,int F,int T,int sum) {
	if(cur==N) {
		G[F|T]+=p2[sum];
	}
	else {
		if(T&(1<<cur)) {
			dfs(cur+1,F,T,sum);
		}
		else {
			dfs(cur+1,F,T,sum);
			dfs(cur+1,F|(1<<cur),T,sum+__builtin_popcount(E[cur]&T));
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,499) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x]|=1<<y;
		E[y]|=1<<x;
	}
	
	for(int mask=0;mask<1<<N;mask++) dfs(0,0,mask,0);
	
	F[0]=G[0]=1;
	for(int mask=1;mask<1<<N;mask++) {
		F[mask]=G[mask]=G[mask]%mo*((mo+1)/2)%mo;
		int msb=0;
		FOR(i,N) if(mask&(1<<i)) msb=1<<i;
		for(int sm=mask; sm&msb; sm=(sm-1)&mask) if(sm!=mask) F[mask]+=mo-F[sm]*2*G[mask^sm]%mo;
		F[mask]%=mo;
	}
	
	cout<<F[(1<<N)-1]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
