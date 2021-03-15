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

int H,W;
int Y[2],X[2];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>Y[0]>>X[0]>>Y[1]>>X[1];
	
	int A=min(X[0],X[1])-1;
	int B=W-max(X[0],X[1]);
	int C=min(Y[0],Y[1])-1;
	int D=H-max(Y[0],Y[1]);
	int E=abs(X[0]-X[1])+abs(Y[0]-Y[1]);
	
	ll ret=1;
	for(i=1;i<=A;i++) ret+=modpow(i+E);
	for(i=1;i<=B;i++) ret+=modpow(i+E);
	for(i=1;i<=C;i++) ret+=modpow(i+E);
	for(i=1;i<=D;i++) ret+=modpow(i+E);
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
