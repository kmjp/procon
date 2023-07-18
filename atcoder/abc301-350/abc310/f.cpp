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


int N;
ll F[1<<11],T[1<<11];
const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mask;
	cin>>N;
	F[1]=1;
	FOR(i,N) {
		cin>>x;
		ll p=modpow(x);
		ZERO(T);
		
		for(j=1;j<=min(10,x);j++) {
			FOR(mask,1<<11) {
				int nmask=mask|(mask<<j);
				nmask&=((1<<11)-1);
				(T[nmask]+=F[mask]*p)%=mo;
			}
		}
		x-=10;
		if(x>0) {
			FOR(mask,1<<11) {
				(T[mask]+=F[mask]*x%mo*p)%=mo;
			}
		}
		swap(F,T);
	}
	ll ret=0;
	FOR(mask,1<<11) if(mask&(1<<10)) ret+=F[mask];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
