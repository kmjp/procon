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


const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;
int N;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int memo[1400][1<<12];
int dmask[1300];

int dfs(int id,int mask) {
	if(prime[id]>N) return 0;
	if(memo[id][mask]>=0) return memo[id][mask];
	memo[id][mask]=dfs(id+1,mask);
	for(int x=prime[id];x<=N;x+=prime[id]) {
		int y;
		for(y=id+1;prime[y]<=N;y++) if(x%prime[y]==0) break;
		if(prime[y]>N && (dmask[x]&mask)==0) memo[id][mask]=max(memo[id][mask], x+dfs(id+1,mask|dmask[x]));
	}
	return memo[id][mask];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cprime();
	MINUS(memo);
	for(i=2;i<=1270;i++) {
		FOR(j,20) if(prime[j]<32 && i%prime[j]==0) dmask[i] |= 1<<j;
	}
	
	cin>>N;
	cout<<dfs(0,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
