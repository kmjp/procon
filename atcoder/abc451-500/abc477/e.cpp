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

int N,Q;
int A[202020],B[202020];
vector<pair<int,int>> E[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

ll dp[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		bt.add(i+1,A[i]);
		bt.add(N+i+1,A[i]);
		bt.add(2*N+i+1,A[i]);
		E[i].push_back({(i+1)%N,A[i]});
		E[(i+1)%N].push_back({i,A[i]});
	}
	FOR(i,N) {
		cin>>B[i];
		E[i].push_back({N,B[i]});
		E[N].push_back({i,B[i]});
		dp[i]=1LL<<60;
	}
	priority_queue<pair<ll,int>> PQ;
	PQ.push({-dp[N],N});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		if(dp[cur]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) PQ.push({-dp[e],e});
	}
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--,R--;
		if(R==N) {
			cout<<dp[L]<<endl;
		}
		else {
			ll ret=dp[L]+dp[R];
			ret=min(ret,bt(R)-bt(L));
			swap(R,L);
			R+=N;
			ret=min(ret,bt(R)-bt(L));
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
