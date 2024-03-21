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

const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll P1,P2,Q1,Q2,T;
ll Q[1010];

ll from[1010],to[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P1>>P2>>Q1>>Q2>>T;
	P1=P1*modpow(P2)%mo;
	Q1=Q1*modpow(Q2)%mo;
	
	FOR(i,T+1) {
		Q[i]=modpow(Q1,i);
	}
	
	from[1]=1;
	for(i=1;i<=T;i++) {
		ZERO(to);
		FOR(j,i+2) {
			// add
			(to[1]+=from[j]*P1)%=mo;
			(to[j+1]+=from[j]*Q[j])%=mo;
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,T+2) ret+=from[i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
