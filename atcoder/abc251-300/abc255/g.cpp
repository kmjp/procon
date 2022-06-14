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


int N,M;
ll A[202020];
ll X[202020],Y[202020];
map<ll,vector<ll>> NG;
map<ll,ll> G,H;

ll getG(ll n) {
	if(G.count(n)) return G[n];
	auto it=H.lower_bound(n);
	it--;
	ll n2=it->first;
	return n-it->first+it->second;
}
ll getH(ll n) {
	if(H.count(n)) return H[n];
	auto it=H.lower_bound(n);
	it--;
	ll n2=it->first;
	return n-it->first+it->second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		NG[X[i]].push_back(Y[i]);
	}
	NG[0].clear();
	G[0]=H[0]=0;
	map<ll,int> cnt;
	FORR2(a,b,NG) if(a) {
		ll cand=getH(a-1)+1;
		ll emp=cand;
		map<ll,int> rem;
		FORR(c,b) {
			ll g=getG(a-c);
			if(rem.count(g)) {
				rem[g]--;
			}
			else if(cnt.count(g)) {
				rem[g]=cnt[g];
			}
			else {
				rem[g]=0;
			}
			if(rem[g]==0) emp=min(emp,g);
		}
		G[a]=emp;
		H[a]=max(getH(a-1),G[a]);
		if(cand!=emp) cnt[emp]++;
		
	}
	
	
	ll gr=0;
	FOR(i,N) gr^=getG(A[i]);
	if(gr) {
		cout<<"Takahashi"<<endl;
	}
	else {
		cout<<"Aoki"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
