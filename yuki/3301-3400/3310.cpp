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

int T;
int N,M;
const ll mo=998;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int vis[1010];
ll hoge(int N,int lp) {
	if(lp==0) return 0;
	if(lp%2) {
		return (1+hoge(N,lp-1)*N)%mo;
	}
	ll a=hoge(N,lp/2);
	ll b=modpow(N,lp/2);
	return a*(1+b)%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		ll lp=0;
		
		while(M--) {
			cin>>s;
			if(s.size()<=6) {
				lp=atoi(s.c_str());
			}
			else {
				lp=0;
				FORR(c,s) lp=(lp*10+c-'0')%(998*996);
				lp+=998*996;
			}
			ll sum=hoge(N,lp+1);
			
			cout<<sum%998<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
