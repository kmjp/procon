#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int Z[101010];
int num[101010][2];
ll mo=1000000007;

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		divp[i]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	FOR(i,N) cin>>Z[i];
	sort(Z,Z+N);
	reverse(Z,Z+N);
	
	FOR(i,N) {
		x=Z[i];
		while(x>1) {
			num[divp[x]][(i>=N/2)]++;
			x/=divp[x];
		}
	}
	
	ll v[2]={1,1};
	for(i=2;i<=101000;i++) {
		FOR(j,abs(num[i][0]-num[i][1])) (v[num[i][0]<num[i][1]]*=i)%=mo;
	}
	_P("%lld %lld\n",v[0],v[1]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
