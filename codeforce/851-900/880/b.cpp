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

ll N,M,K;
ll X[1010101];

ll hoge(ll v) {
	int a=lower_bound(X,X+N,v)-X;
	int b=lower_bound(X,X+N,v+1)-X;
	
	ll L=(b<K)?0:(v+X[b-K])/2+1;
	ll R=(a+K-1>=N)?M:(v+X[a+K-1]-1)/2;
	return R-L+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>X[i];
	sort(X,X+N);
	
	pair<ll,ll> ret={hoge(0),0};
	
	FOR(i,N) {
		ll L=(i==0)?max(0LL,X[i]-2):max(X[i]-2,X[i-1]+3);
		ll R=min(M,X[i]+2);
		for(ll a=L;a<=R;a++) {
			ll v=hoge(a);
			if(v>ret.first) {
				ret.first=v;
				ret.second=a;
			}
		}
	}
	cout<<ret.first<<" "<<ret.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
