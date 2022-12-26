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

int K;
ll N;
ll A[1010],B[1010];
ll X[1010],Y[1010];
ll dp[1010];

ll ok(ll v) {
	int i;
	
	if(N<K) return A[N]>=v;
	vector<int> cand;
	FOR(i,K) if(B[K-1-i]>=v) cand.push_back(i+1);
	if(cand.empty()) return 0;
	int T=cand.back();
	
	priority_queue<pair<ll,ll>> Q;
	FOR(i,T) dp[i]=1LL<<60;
	FOR(i,K) if(A[i]>=v) {
		FORR(c,cand) if(i+c>=K) dp[(i+c)%T]=min(dp[(i+c)%T],(ll)i+c);
	}
	FOR(i,T) Q.push({-dp[i],i});
	
	while(Q.size()) {
		ll cur=-Q.top().first;
		int tar=Q.top().second;
		Q.pop();
		if(dp[tar]!=cur) continue;
		if(cur>N) return 0;
		if(N%T==tar) return 1;
		FORR(c,cand) if(cur+c>=K&&dp[(cur+c)%T]>cur+c) {
			dp[(cur+c)%T]=cur+c;
			Q.push({-(cur+c),(cur+c)%T});
		}
	}
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,K) cin>>A[i];
	FOR(i,K) cin>>B[i];
	
	ll ret=-1LL<<60;
	for(i=60;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
