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

int N,M;
ll mo=1000000007;
ll ret=0;

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void dfs(int cur,ll mul,int sgn) {
	(ret+=mo+(N/M/mul)*(N/M/mul)%mo*sgn)%=mo;
	int i;
	for(i=cur;mul*prime[i]<=N/M;i++) {
		dfs(i+1,mul*prime[i],-sgn);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	cin>>s;
	vector<int> A;
	FORR(c,s) A.push_back(c-'0');
	
	while(A.size()>1) {
		vector<int> B;
		FOR(i,A.size()-1) {
			if(i%2==0) B.push_back(min(A[i],A[i+1]));
			else B.push_back(max(A[i],A[i+1]));
		}
		A=B;
		FORR(c,A) cout<<c;
		cout<<endl;
	}
	return;
	*/
	
	cin>>N>>M;
	if(M>N) return _P("0\n");
	cprime();
	dfs(0,1,1);
	ret+=mo-1;
	
	for(i=1;i<=N-2;i++) ret=ret*i%mo;
	cout<<ret%mo<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
