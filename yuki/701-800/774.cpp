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
int A[10];
ll ret=-1;
vector<ll> V;
bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

// ƒ~ƒ‰[ƒ‰ƒrƒ“
ll modpow(__int128_t a, ll n, ll mo) {
	__int128_t r=1;
	a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
bool MillerRabin(ll v,int loop=10) {
	ll d=v-1;
	int s=0,i,j;
	if(v<=1) return false;
	if(v==2) return true;
	if(v%2==0) return false;
	while(d%2==0) d/=2,s++;
	
	FOR(i,loop) {
		ll a=abs(1LL*rand()*rand()+rand())%(v-2)+1;
		ll r=modpow(a,d,v);
		if(r==1 || r==v-1) continue;
		FOR(j,s) {
			r=modpow(r,2,v);
			if(r==v-1) break;
		}
		if(j==s) return false;
	}
	return true;
}

void dfs(ll cur,int mask) {
	if(mask==(1<<N)-1) V.push_back(cur);
	
	int i;
	FOR(i,N) if((mask&(1<<i))==0) {
		ll ne;
		if(A[i]>=10) ne=cur*100+A[i];
		else ne=cur*10+A[i];
		dfs(ne,mask|(1<<i));
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	int ma=-1;
	dfs(0,0);
	srand(time(NULL));
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	reverse(ALL(V));
	FORR(v,V) {
		if(MillerRabin(v,30)) {
		cout<<v<<endl;
		return;
		}
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
