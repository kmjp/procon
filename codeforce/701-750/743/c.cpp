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

int T,N;
int A[3030];
int dp[3030][3030];
vector<int> pre[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) pre[i].clear();
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			if(i&&A[i]==A[i-1]) {
				i--;
				N--;
			}
		}
		for(int R=1;R<=N;R++) {
			for(int L=0;L<R-1;L++) dp[L][R]=dp[L][R-1]+1;
			dp[R-1][R]=0;
			FORR(p,pre[A[R-1]]) {
				for(int L=0;L<p;L++) {
					dp[L][R]=min(dp[L][R],dp[L][p]+dp[p][R-1]+1);
				}
			}
			/*
			cout<<R<<" ";
			for(int L=0;L<R;L++) cout<<L<<":"<<dp[L][R]<<" ";
			cout<<endl;
			*/
			pre[A[R-1]].push_back(R);
		}
		cout<<dp[0][N]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
