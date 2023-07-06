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
ll M,A;
ll X[303030];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll getGr(ll v) {
	if(A==0) {
		return v;
	}
	if(M==2) return v%2;
	if(2*A<=M) {
		if(v<M) return (v/A)%2;
		//ˆê”Ôã‚Ì—ñ
		ll f=v%M;
		if(f/A==0) return (getGr(v-A)!=0)^1;
		if(f/A==1) return getGr(v-A)+1;
		return (f/A)%2;
	}
	else {
		ll S=M-A;
		ll D=M-v%M;
		ll a=(D+S-1)/S-1;
		if(a==0) {
			D+=M;
			a=(D+S-1)/S-1;
		}
		return min(v/A,a-1);
		
	}
}

ll getGrNum(ll gr,ll n) {
	if(A==0) {
		return gr<n;
	}
	if(M==2) {
		if((n-1)%2==gr) return (n+1)/2;
		return 0;
	}
	
	if(2*A<=M) {
		if(n<A) return 0;
		if(gr>2) return 0;
		int v=getGr(n);
		ll num=(n-A)/M+1;
		if(v==2) {
			if(gr==0) return 1;
			if(gr==1) return num-1;
			if(gr==2) return 0;
		}
		if(v==1) {
			if(gr==0) return num;
			return 0;
		}
		if(v==0) {
			if(gr==0) return 0;
			int v2=getGr(n-A);
			if(v2==1) {
				if(gr==1) return num;
				else return 0;
			}
			else {
				if(gr==1) return 1;
				else return num-1;
			}
			
		}
	}
	else {
		if(n<A) return (gr==0);
		n-=A;
		ll a=getGr(n);
		ll num=(n+M)/M;
		int is0=(n%M)<A;
		if(is0) {
			if(gr<a) {
				return 1;
			}
			else if(gr==a) {
				return num-a;
			}
			else {
				return 0;
			}
		}
		else {
			if(gr==0||gr>a) return 0;
			if(gr<a) return 1;
			return num-(a-1);
		}
		
		
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>A;
	ll G=__gcd(M,A);
	M/=G;
	A/=G;
	int gr[33]={};
	FOR(i,30) {
		set<int> S;
		for(x=A;x<=i;x+=M) S.insert(gr[i-x]);
		while(S.count(gr[i])) gr[i]++;
	}
	
	ll ret=0;
	ll nim=0;
	FOR(i,N) {
		cin>>X[i];
		X[i]/=G;
		nim^=getGr(X[i]);
		//cout<<X[i]<<" "<<getGr(X[i])<<" "<<nim<<endl;
	}
	//cout<<nim<<endl;
	FOR(i,N) {
		ret+=getGrNum(nim^getGr(X[i]),X[i])%mo;
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
