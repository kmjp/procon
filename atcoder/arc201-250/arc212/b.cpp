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
int X[202020],Y[202020],C[202020];

vector<pair<int,int>> E[404040];
ll dp[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i]>>C[i];
		X[i]--;
		Y[i]--;
		if(i) {
			E[X[i]].push_back({Y[i],C[i]});
		}
	}
	
	if(X[0]==Y[0]) {
		cout<<C[0]<<endl;
		return;
	}
	FOR(i,2*N) dp[i]=1LL<<60;
	
	priority_queue<pair<ll,int>> Q;
	dp[Y[0]]=C[0];
	Q.push({-C[0],Y[0]});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		if(cur==X[0]) {
			cout<<co<<endl;
			return;
		}
		FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) Q.push({-dp[e],e});
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
