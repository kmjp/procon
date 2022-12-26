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

ll N,K;
map<ll,ll> memo;

ll hoge(ll N) {
	if(N<=0) return 0;
	if(memo.count(N)) return memo[N];
	if(N<K) return memo[N]=min(K-1,N);
	ll p=1;
	while(N/p>=K) p*=K;
	ll& ret=memo[N];
	ret=0;
	if(N==p) {
		ret=1;
		while(p>1) ret*=(K-1),p/=K;
	}
	else if(N/p==K-1) {
		ret=(K-1)*hoge(N/K);
	}
	else {
		ret=(N/p)*hoge(p)+hoge(N%p);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cout<<hoge(N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
