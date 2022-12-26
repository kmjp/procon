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
vector<int> R[202020];
vector<int> G[202020];

int vis[202020];
int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x;
		R[i].resize(x);
		FOR(j,x) {
			cin>>R[i][j];
			R[i][j]--;
			G[R[i][j]].push_back(i);
		}
	}
	MINUS(dp);
	dp[0]=0;
	vector<int> cand;
	cand.push_back(0);
	while(cand.size()) {
		int mex=dp[cand[0]]+1;
		vector<int> ncand;
		FORR(c,cand) FORR(g,G[c]) if(vis[g]==0) {
			vis[g]=1;
			FORR(r,R[g]) if(dp[r]==-1) {
				dp[r]=mex;
				ncand.push_back(r);
			}
		}
		swap(ncand,cand);
	}
	
	FOR(i,N) cout<<dp[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
