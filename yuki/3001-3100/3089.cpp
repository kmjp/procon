#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll M;
int N;
string S;
ll C[10];
ll D[10];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,10) {
		C[i]=M/10+(i<(M%10));
	}
	cin>>S;
	N=S.size();
	reverse(ALL(S));
	FOR(i,N-1) D[S[i]-'0']++;
	
	ll p=C[S.back()-'0'];
	if(S.back()=='0') p--;
	
	ll ret=0;
	FOR(i,N-1) {
		x=S[i]-'0';
		//残りのパターン
		D[x]--;
		ll pat=modpow(M,i)*(p%mo)%mo;
		FOR(j,10) pat=pat*modpow(C[j],D[j])%mo;
		
		ll sum=1LL*C[x]%mo*x%mo;
		(sum+=5*(C[x]%mo)%mo*((C[x]-1)%mo))%=mo;
		
		(ret+=pat*sum)%=mo;
		
		D[x]++;
	}
	{
		x=S.back()-'0';
		ll pat=modpow(M,N-1);
		FOR(j,10) pat=pat*modpow(C[j],D[j])%mo;
		
		ll sum=1LL*C[x]%mo*x%mo;
		(sum+=5*(C[x]%mo)%mo*((C[x]-1)%mo))%=mo;
		
		(ret+=pat*sum)%=mo;
	}
	
	
	
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
