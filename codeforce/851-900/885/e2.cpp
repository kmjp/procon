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

ll X;
int Q;
ll mo;

map<int,int> M;
ll ret;
int num;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void hoge(int n) {
	int a=n+1;
	while(a%mo==0) a/=mo, num++;
	while(n%mo==0) n/=mo, num--;
	ret=ret*a%mo*modpow(n)%mo;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Q>>mo;
	while(X%2==0) X/=2;
	ret=1;
	for(i=2;i*i<=X;i++) while(X%i==0) {
		X/=i;
		hoge(++M[i]);
	}
	if(X>1) {
		hoge(++M[X]);
	}
	while(Q--) {
		cin>>X;
		while(X%2==0) X/=2;
		for(i=2;i*i<=X;i++) while(X%i==0) {
			X/=i;
			hoge(++M[i]);
		}
		if(X>1) {
			hoge(++M[X]);
		}
		
		if(num) {
			cout<<0<<endl;
		}
		else {
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
