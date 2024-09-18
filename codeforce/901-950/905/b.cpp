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

int N,T,K;
int M[202020];
set<pair<int,int>> G[202020];

vector<pair<int,int>> C[202020];

void open(int v) {
	FORR2(k,t,C[v]) G[k].insert({v,t});
	C[v].clear();
}
int dp[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,T) {
		cin>>M[i];
		FOR(x,M[i]) {
			cin>>k>>l;
			k--,l--;
			C[k].push_back({i,l});
			C[l].push_back({i,k});
		}
	}
	FOR(i,N) dp[i]=1<<20;
	dp[0]=0;
	open(0);
	cin>>K;
	FOR(i,K) {
		int v;
		cin>>v;
		v--;
		vector<int> add;
		FORR2(a,b,G[v]) {
			if(dp[a]<1<<20&&dp[b]==1<<20) {
				dp[b]=i+1;
				add.push_back(b);
			}
			if(dp[b]<1<<20&&dp[a]==1<<20) {
				dp[a]=i+1;
				add.push_back(a);
			}
		}
		G[v].clear();
		FORR(a,add) open(a);
		if(dp[N-1]<1<<20) {
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
