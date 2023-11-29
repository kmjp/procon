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

int N,M,K;
ll C[202020];
ll A[202020];
ll cnt[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>C[i];
		C[i]--;
	}
	FOR(i,M) cin>>A[i];
	ll mi=1LL<<60;
	multiset<ll> cand;
	FOR(i,M) {
		cnt[i]=K;
		cand.insert(1LL*K*A[i]);
	}
	FOR(i,N) {
		x=C[i];
		cand.erase(cand.find(cnt[x]*A[x]));
		cnt[x]--;
		cand.insert(cnt[x]*A[x]);
		
		if(i>=K) {
			x=C[i-K];
			cand.erase(cand.find(cnt[x]*A[x]));
			cnt[x]++;
			cand.insert(cnt[x]*A[x]);
		}
		if(i>=K-1) mi=min(mi,*cand.begin());
		
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
