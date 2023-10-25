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

int N,W,D;
int A[555];
int S[555];
int dp[450][102000];
int best[450][450];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>D;
	for(i=1;i<N;i++) {
		cin>>A[i];
	}
	
	for(i=1;i<N;i++) {
		priority_queue<int> Q;
		FOR(j,W) Q.push(0);
		int sum=0;
		for(j=i;j<N;j++) {
			sum+=A[j];
			Q.push(-A[j]);
			sum+=Q.top();
			Q.pop();
			best[i][j]=sum;
		}
	}
	
	D/=2;
	MINUS(dp);
	dp[0][0]=0;
	int ma=0;
	FOR(i,N) {
		int be=-1;
		FOR(j,D+1) if(dp[i][j]>be) {
			be=dp[i][j];
			for(k=i+1;k<=N-1&&j+k<=D;k++) chmax(dp[k][j+k],be+best[i+1][k]);
		}
		ma=max(ma,be);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
