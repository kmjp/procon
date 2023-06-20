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
vector<int> V[4];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll pat=1;
	int num=0;
	FOR(i,N) {
		cin>>s>>x;
		if(s=="U") V[0].push_back(x);
		if(s=="F") V[1].push_back(x);
		if(s=="W") V[2].push_back(x);
		if(s=="P") {
			pat=pat*modpow(N-1,x)%mo;
			num++;
		}
	}
	pat=pat*num%mo;
	FOR(i,3) {
		ll sum=0;
		FORR(v,V[i]) sum+=v;
		ll npat=0;
		FORR(v,V[i]) {
			ll a=modpow(N-1,sum-v);
			ll b=modpow(N-1,v)+mo-modpow(N-2,v);
			(npat+=a*b)%=mo;
		}
		pat=pat*npat%mo;
	}
	cout<<pat<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
