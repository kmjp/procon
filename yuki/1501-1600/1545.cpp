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

int N,S,T,K,M;
int X[101010];
int A[101010],B[101010];
vector<vector<int>> E[1505050];
ll dp[2020202];
int from[2020202];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T>>K;
	S--,T--;
	FOR(i,N) cin>>X[i];
	cin>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		FOR(j,K-1) {
			E[N*j+x].push_back({N*(j+1)+y,i,X[y]+k});
		}
		E[N*(K-1)+x].push_back({N*(K-1)+y,i,X[y]+k});
	}
	FOR(i,N*K) dp[i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[S]=X[S];
	Q.push({-X[S],S});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FORR(e,E[cur]) if(dp[e[0]]>co+e[2]) {
			dp[e[0]]=co+e[2];
			from[e[0]]=cur;
			Q.push({-dp[e[0]],e[0]});
		}
	}
	
	if(dp[N*(K-1)+T]==1LL<<60) {
		cout<<"Impossible"<<endl;
	}
	else {
		cout<<"Possible"<<endl;
		cout<<dp[N*(K-1)+T]<<endl;
		int cur=N*(K-1)+T;
		vector<int> V;
		while(cur!=S) {
			V.push_back(cur);
			cur=from[cur];
		}
		V.push_back(S);
		reverse(ALL(V));
		cout<<V.size()<<endl;
		FORR(v,V) cout<<(v%N+1)<<" ";
		cout<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
