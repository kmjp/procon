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
ll V,X[101010],Y[101010];
ll S[101010],T[101010];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	ll SS=0,ST=0,SST=0;
	FOR(i,N) {
		S[i]=1;
		T[i]=1;
		FOR(j,N) if(i!=j) {
			S[i]=S[i]*(V-X[j])%mo;
			T[i]=T[i]*(X[i]-X[j])%mo;
		}
		T[i]=Y[i]*modpow(T[i]%mo+mo)%mo;
		(SS+=S[i])%=mo;
		(ST+=T[i])%=mo;
		(SST+=S[i]*T[i])%=mo;
	}
	
	ll ret=(N*SST-SS*ST)%mo;
	cout<<(ret+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
