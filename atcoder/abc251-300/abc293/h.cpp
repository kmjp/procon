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

int N;
vector<int> E[202020];
int K;
int ok;

int dp[202020];
int t[202020];

void dfs(int cur,int pre) {
	if(E[cur].size()==1&&E[cur][0]==pre) {
		dp[cur]=1;
		t[cur]=1;
		return;
	}
	int ma=0;
	vector<int> X[2];
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		X[t[e]].push_back(dp[e]);
	}
	sort(ALL(X[0]));
	sort(ALL(X[1]));
	reverse(ALL(X[0]));
	reverse(ALL(X[1]));
	
	if(X[1].size()<=1) {
		vector<int> Y;
		FORR(a,X[0]) Y.push_back(a);
		FORR(a,X[1]) Y.push_back(a-1);
		sort(ALL(Y));
		reverse(ALL(Y));
		if(Y[0]+1>K) ok=0;
		if(Y.size()>=2&&Y[0]+Y[1]+1>K) ok=0;
		t[cur]=1;
		dp[cur]=Y[0]+1;
	}
	else {
		X[1][0]--;
		vector<int> Y;
		FORR(a,X[0]) Y.push_back(a);
		FORR(a,X[1]) Y.push_back(a);
		sort(ALL(Y));
		reverse(ALL(Y));
		int cand=Y[0]+1;
		if(Y[0]+1>K) cand=1<<20;
		if(Y.size()>=2&&Y[0]+Y[1]+1>K) cand=1<<20;
		
		X[1][1]--;
		Y.clear();
		FORR(a,X[0]) Y.push_back(a);
		FORR(a,X[1]) Y.push_back(a);
		sort(ALL(Y));
		reverse(ALL(Y));
		if(Y[0]+1>K) ok=0;
		if(Y.size()>=2&&Y[0]+Y[1]+1>K) ok=0;
		if(Y[0]+1<cand) {
			t[cur]=0;
			dp[cur]=Y[0]+1;
		}
		else {
			t[cur]=1;
			dp[cur]=cand;
		}
		
		
	}
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	int ret=N;
	for(i=20;i>=0;i--) {
		K=ret-(1<<i);
		if(K>=1) {
			ok=1;
			dfs(0,0);
			if(ok) ret=K;
		}
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
