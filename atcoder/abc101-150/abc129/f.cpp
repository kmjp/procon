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

ll L,A,B,mo;
ll F[20];
ll num[20];
ll p10[20];
ll S[20];

ll modpow(ll a, __int128 n) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll len,ll p) {
	if(len==0) return 0;
	if(len==1) return 1;
	ll a=modpow(p,len/2);
	ll v=hoge(len/2,p);
	if(len%2==0) {
		return v*(1+a)%mo;
	}
	else {
		return (v*(1+a)+a*a)%mo;
	}
}
ll hoge2(ll len,ll p) {
	if(len<=0) return 0;
	if(len==1) return 1;
	
	if(len%2==0) {
		ll a=modpow(p,len/2);
		ll v=hoge2(len/2,p);
		return (v*(1+a)+(len/2)%mo*hoge(len/2,p))%mo;
	}
	else {
		return (hoge2(len-1,p)+hoge(len,p))%mo;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>A>>B>>mo;
	
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	
	ll w=L;
	ll v=A;
	for(i=1;i<=19;i++) if(v<p10[i] && w) {
		ll d=min(w,(p10[i]-v+B-1)/B);
		F[i]=v;
		num[i]=d;
		v+=B*d;
		w-=d;
	}
	ll c=1;
	ll ret=0;
	for(i=19;i>=1;i--) if(num[i]) {
		
		ll p=p10[i]%mo;
		ll n=num[i];
		ll a=F[i];
		
		ll r=(F[i]%mo*hoge(n,p)+B%mo*hoge2(n-1,p))%mo;
		ret+=r*c%mo;
		c=c*modpow(10,__int128(i)*num[i])%mo;
		
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
