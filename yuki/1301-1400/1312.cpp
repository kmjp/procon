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

ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N==1) return _P("2\n");
	if(N==2) return _P("3\n");
	
	set<ll> ret;
	ret.insert(N-1);
	for(ll a=2;a*a<=N;a++) {
		set<ll> S;
		ll x=N;
		while(x) {
			S.insert(x%a);
			x/=a;
		}
		if(S.size()==1) ret.insert(a);
	}
	
	for(ll a=1;a*(a+1)+a<=N;a++) {
		ll v=N-a;
		if(v%a==0) {
			ll w=v/a;
			if(w>a) ret.insert(w);
		}
	}
	
	cout<<*ret.begin()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
