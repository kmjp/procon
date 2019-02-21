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

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int N;
int A[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	int g=0;
	FOR(i,N) {
		cin>>A[i];
		g=__gcd(g,A[i]);
	}
	FOR(i,N-1) if(A[i]!=A[i+1]) break;
	if(i==N-1) return _P("-1\n");
	
	
	map<int,int> M;
	FOR(i,N) {
		x=A[i]/g;
		for(j=0;prime[j]*prime[j]<=x;j++) {
			if(x%prime[j]==0) {
				M[prime[j]]++;
				while(x%prime[j]==0) x/=prime[j];
			}
		}
		if(x>1) M[x]++;
	}
	
	int ma=0;
	FORR(m,M) ma=max(ma,m.second);
	cout<<N-ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
