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
ll K;
ll A[303030];

ll num[603030],sum[603030];

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>N>>K;
	ll s=0;
	ll ma=0;
	FOR(i,N) {
		cin>>A[i];
		s+=A[i];
		ma=max(ma,A[i]);
		num[A[i]]+=1;
		sum[A[i]]+=A[i];
	}
	for(i=1;i<=602020;i++) {
		num[i]+=num[i-1];
		sum[i]+=sum[i-1];
	}
	
	
	ll lef=1LL*N*ma-s;
	if(lef<=K) {
		cout<<(s+K)/N<<endl;
		return;
	}
	int ret=1;
	for(i=2;i<=ma;i++) {
		ll need=0;
		for(x=0;x<=ma;x+=i) {
			ll nu=num[x+i-1]-num[x];
			ll su=sum[x+i-1]-sum[x];
			need+=nu*(x+i)-su;
		}
		if(need<=K) ret=i;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
