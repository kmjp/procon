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


int T;
int N,Q;
vector<int> E[2020];
int P[2020];
int ma[2020];

ll dp[2020][2020];

void dfs(int cur, int pre) {
	P[cur]=pre;
	if(cur) ma[cur]=E[cur].size();
	
	int ma=0;
	int x=cur;
	int i;
	int more=0;
	while(P[P[x]]) {
		x=P[P[x]];
		if(E[x].size()>=E[cur].size()) more++;
	}
	
	if(cur) {
		ll fail=E[cur].size();
		if(P[cur]==0) {
			dp[cur][0]=2*fail-1;
			
			for(i=1;i<=2000;i++) {
				dp[cur][i]=1;
			}
		}
		else {
			
			FOR(i,2010) {
				if(i<=more) {
					dp[cur][i]=2*fail+dp[P[P[cur]]][i];
				}
				else {
					dp[cur][i]=2+dp[P[P[cur]]][i-1];
				}
			}
		}
	}
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,0);
		while(Q--) {
			cin>>x>>y;
			cout<<1+dp[P[x-1]][y]<<endl;
		}
	}
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
