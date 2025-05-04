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
int C[2020],A[2020];

int dp[2020];
int hoge(int a,int b) {
	int i,x;
	FOR(i,N) dp[i]=1<<20;
	dp[b]=0;
	for(i=b;i>=a;i--) {
		for(x=1;x<=C[i];x++) chmin(dp[i-x],dp[i]+1);
	}
	return dp[a];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) cin>>C[i+1];
	FOR(i,N-1) cin>>A[i+1];
	A[0]=1;
	
	vector<int> V;
	FOR(i,N) if(A[i]) V.push_back(i);
	int ret=0;
	FOR(i,V.size()-1) ret+=hoge(V[i],V[i+1]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
