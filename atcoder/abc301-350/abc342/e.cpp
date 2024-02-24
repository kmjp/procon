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
ll dp[202020];
ll L[202020],D[202020],K[202020],C[202020];
vector<pair<int,int>> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>L[i]>>D[i]>>K[i]>>C[i]>>x>>y;
		E[y-1].push_back({x-1,i});
	}
	FOR(i,N) dp[i]=-1;
	dp[N-1]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	Q.push({dp[N-1],N-1});
	while(Q.size()) {
		ll co=Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FORR2(e,i,E[cur]) {
			ll first=L[i]+C[i];
			ll la=L[i]+D[i]*(K[i]-1)+C[i];
			ll nex;
			if(co>=la) {
				nex=la-C[i];
			}
			else if(co>=first) {
				nex=(co-first)/D[i]*D[i]+L[i];
			}
			else {
				continue;
			}
			if(chmax(dp[e],nex)) Q.push({nex,e});
		}
	}
	
	FOR(i,N-1) {
		if(dp[i]==-1) {
			cout<<"Unreachable"<<endl;
		}
		else {
			cout<<dp[i]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
