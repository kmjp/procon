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

const int prime_max = 10000001;
short divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}
ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int T;
int N,X,A,B,M;
int num[12];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>T;
	while(T--) {
		cin>>N>>X>>A>>B>>M;
		
		ll ret=0;
		ZERO(num);
		
		for(i=0;i<N;i++) {
			
			if(num[3]<2) {
				x = 1;
				for(j=2;j<=8;j++) x = x*modpow(j,num[j],9);
				ret += x*(X%10);
			}
			else {
				ret += 9*(X%10);
			}
			
			if(i<N-1) {
				x = N-1-i;
				y = 1+i;
				while(divp[x]) num[divp[x]%9]++, x /= divp[x];
				num[x%9]++;
				while(divp[y]) num[divp[y]%9]--, y /= divp[y];
				num[y%9]--;
			}
			
			X = ((X^A)+B)%M;
		}
		while(ret>=10) ret=ret%10+ret/10;
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
