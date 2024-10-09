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

int Q;
ll L,R;
const ll mo=1000000007;
vector<ll> cand[66];
ll hoge(ll v) {
	ll ret=0;
	int i;
	for(ll x=2;x<=60;x++) {
		ll AL=1LL<<x;
		ll AR=min(2LL<<x,v+1);
		if(AR<=AL) break;
		FOR(i,cand[x].size()-1) {
			ll a=max(AL,cand[x][i]);
			ll b=min(AR,cand[x][i+1]);
			if(a<b) (ret+=(b-a)%mo*i)%=mo;
		}
	}
	
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(ll x=2;x<=60;x++) {
		ll AL=1LL<<x;
		ll AR=2LL<<x;
		ll cur=1;
		for(int z=0;z<=60;z++) {
			cand[x].push_back(cur);
			if(cur>=(1LL<<60)/x) {
				cand[x].push_back(1LL<<60);
				break;
			}
			cur*=x;
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>L>>R;
		ll ret=hoge(R)-hoge(L-1)+mo;
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
