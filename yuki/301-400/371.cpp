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

ll L,H;

const int prime_max = 100005;
int NP,divp[prime_max];
ll prime[100000];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>H;
	cprime();
	for(i=NP-1;i>=0;i--) if(1LL*prime[i]*prime[i]<=H) {
		for(ll a=H/prime[i]*prime[i];a>=max(L,1LL*prime[i]*prime[i]);a-=prime[i]) {
			FOR(x,i) if(a%prime[x]==0) break;
			if(x==i) return _P("%lld\n",a);
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
