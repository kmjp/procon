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
int A,B,S;
const ll mo=998244353;

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll from[2][403][403];
ll to[2][403][403];
ll po[403][403];

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	FOR(i,401) {
		po[i][0]=1;
		FOR(j,401) po[i][j+1]=po[i][j]*i%mo;
	}
	
	cin>>N;
	from[0][0][0]=1;
	FOR(i,N) {
		cin>>A>>B;
		S+=A;
		memmove(to,from,sizeof(from));
		FOR(j,2) FOR(x,403) FOR(y,403) if(from[j][x][y]) {
			FOR(r,B) {
				(to[j^1][x+A][y+r]+=from[j][x][y]*po[A][r]%mo*factr[r])%=mo;
			}
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(j,2) FOR(x,403) FOR(y,403) if(x && from[j][x][y]) {
		ll p=S*modpow(x)%mo*fact[y]%mo*from[j][x][y]%mo*modpow(modpow(x,y))%mo;
		if(j) ret+=p;
		else ret+=mo-p;
	}
	
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
