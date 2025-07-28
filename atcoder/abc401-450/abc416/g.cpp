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
int K;
string S[202020];
int A[202020];
int dp[1<<20];

bool cmp(int a,int b) {
	if(S[a]+S[b]<S[b]+S[a]) return 1;
	if(S[a]+S[b]>S[b]+S[a]) return 0;
	if(S[a].size()<S[b].size()) return 1;
	if(S[a].size()>S[b].size()) return 0;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	set<string> cand;
	FOR(i,N) {
		cin>>S[i];
		cand.insert(S[i]);
		A[i]=i;
	}
	sort(A,A+N,cmp);
	string T;
	FOR(i,K) T+=S[A[0]];
	N=T.size();
	FOR(i,N+1) dp[i]=-1000000;
	dp[0]=0;
	FOR(i,N+1) if(dp[i]>=0) {
		if(dp[i]==K) {
			cout<<T.substr(0,i)<<endl;
			return;
		}
		for(j=1;j<=10;j++) if(i+j<=T.size()) {
			
			if(cand.count(T.substr(i,j))) dp[i+j]=max(dp[i+j],dp[i]+1);
		}
		
	}
	cout<<T<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
