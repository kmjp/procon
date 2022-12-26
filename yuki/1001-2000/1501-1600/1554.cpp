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

int T,N,K;
int A[101010];
int X[101010];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		auto cmp = [](int L,int R) {
			return 1LL*A[L]*(X[R]+1)<1LL*A[R]*(X[L]+1);
		};
		priority_queue<int,vector<int>,decltype(cmp)> Q(cmp);
		cin>>N>>K;
		ll S=0;
		FOR(i,N) {
			cin>>A[i];
			S+=A[i];
			X[i]=0;
			Q.push(i);
		}
		ll ret=1;
		FOR(i,K) {
			x=Q.top();
			Q.pop();
			X[x]++;
			ret=ret*(1+i)%mo;
			ret=ret*modpow(X[x])%mo;
			ret=ret*A[x]%mo;
			ret=ret*modpow(S)%mo;
			Q.push(x);
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
