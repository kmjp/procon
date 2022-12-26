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
int D[303];
ll mo=1000000007;
int is1;
ll from[303][603];
ll to[303][603];
ll fact[303];


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>D[i];
		if(D[i]==1) is1++;
	}
	
	fact[0]=1;
	for(i=1;i<=300;i++) fact[i]=fact[i-1]*i%mo;
	
	
	ll ret=0;
	if(is1==0) {
		ret=fact[N-1]*((mo+1)/2)%mo;
		cout<<ret<<endl;
		return;
	}
	
	from[0][0]=1;
	FOR(i,N) {
		FOR(x,302) FOR(y,602) if(from[x][y]) {
			// in cycle
			if(D[i]>1) {
				(to[x+1][y+D[i]-2] += (D[i]-1)*from[x][y])%=mo;
			}
			(to[x][y] += from[x][y])%=mo;
		}
		swap(from,to);
		ZERO(to);
	}
	
	for(x=3;x<=N;x++) FOR(y,602) if(from[x][y]) {
		ret+=y*fact[x-1]%mo*from[x][y]%mo*fact[N-x-1]%mo;
	}
	ll Q=2;
	FOR(i,N) Q=Q*fact[D[i]-1]%mo;
	
	cout<<ret%mo*modpow(Q)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
