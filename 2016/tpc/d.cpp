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
ll V[101010];
ll C[101010];
ll R[101010];

const int prime_max = 100000;
int NP,divp[prime_max];
ll prime[100000];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

map<ll,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	FOR(i,NP) prime[i]=prime[i]*prime[i]*prime[i];
	
	cin>>N;
	int ma=0;
	FOR(i,N) {
		cin>>V[i];
		FOR(j,NP) {
			if(prime[j]>V[i]) break;
			while(V[i]%prime[j]==0) V[i]/=prime[j];
		}
		M[V[i]]++;
		ma=max(ma,M[V[i]]);
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
