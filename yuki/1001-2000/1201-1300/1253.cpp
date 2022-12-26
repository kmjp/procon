#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
ll N;
ll A[3],B[3];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,3) {
			cin>>A[i]>>B[i];
			A[i]=A[i]*modpow(B[i])%mo;
		}
		
		ll pat[8]={};
		for(i=1;i<=7;i++) {
			ll c=0;
			FOR(j,3) if(i&(1<<j)) c+=A[j];
			pat[i]=modpow(c,N);
		}
		pat[3]-=pat[1]+pat[2];
		pat[5]-=pat[1]+pat[4];
		pat[6]-=pat[2]+pat[4];
		pat[7]-=pat[1]+pat[2]+pat[3]+pat[4]+pat[5]+pat[6];
		ll ret=pat[7]+pat[1]+pat[2]+pat[4];
		cout<<(ret%mo+mo)%mo<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
