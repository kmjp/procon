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
int W[40202],V[40202];
ll dp[40202][512];
int L[202020],R[202020],C[202020];
ll ret[202020];
void dfs(int CL,int CR,vector<int> cand) {
	if(CL+1==CR) {
		FORR(c,cand) {
			if(W[CL]<=C[c]) ret[c]=V[CL];
		}
		return;
	}
	int CM=(CL+CR)/2;
	int i,j,x,y;
	FOR(x,501) {
		dp[CM-1][x]=0;
		dp[CM][x]=0;
	}
	for(x=W[CM-1];x<=500;x++) dp[CM-1][x]=V[CM-1];
	for(x=W[CM];x<=500;x++) dp[CM][x]=V[CM];
	for(x=CM-2;x>=CL;x--) {
		FOR(y,501) {
			dp[x][y]=dp[x+1][y];
			if(y>=W[x]) dp[x][y]=max(dp[x][y],dp[x+1][y-W[x]]+V[x]);
		}
		FOR(y,501) dp[x][y+1]=max(dp[x][y+1],dp[x][y]);
	}
	for(x=CM+1;x<CR;x++) {
		FOR(y,501) {
			dp[x][y]=dp[x-1][y];
			if(y>=W[x]) dp[x][y]=max(dp[x][y],dp[x-1][y-W[x]]+V[x]);
		}
		FOR(y,501) dp[x][y+1]=max(dp[x][y+1],dp[x][y]);
	}
	
	
	vector<int> C1,C2;
	FORR(c,cand) {
		if(R[c]<=CM) C1.push_back(c);
		else if(CM<=L[c]) C2.push_back(c);
		else {
			FOR(x,C[c]+1) ret[c]=max(ret[c],dp[L[c]][x]+dp[R[c]-1][C[c]-x]);
		}
	}
	dfs(CL,CM,C1);
	dfs(CM,CR,C2);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>W[i]>>V[i];
	}
	cin>>Q;
	vector<int> cand;
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>C[i];
		L[i]--;
		cand.push_back(i);
	}
	dfs(0,1<<15,cand);
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
