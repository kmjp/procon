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

int M,N;
const ll mo=100000000;
ll modpow(ll a, ll n) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	if(N>M) {
		cout<<"00000000"<<endl;
		return;
	}
	
	int p2=0,p5=0;
	ll p=1,q=1;
	FOR(i,N) {
		x=M-i;
		while(x%2==0) p2++, x/=2;
		while(x%5==0) p5++, x/=5;
		p=p*x%mo;
		x=i+1;
		while(x%2==0) p2--, x/=2;
		while(x%5==0) p5--, x/=5;
		q=q*x%mo;
	}
	
	q=modpow(q,mo/10*4-1);
	p=p*q%mo;
	
	FOR(i,p2) p=p*2%mo;
	FOR(i,p5) p=p*5%mo;
	_P("%08lld\n",p);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
