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
int A[2020];
ll dp[2020][2020];
int from[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	FOR(i,M+1) dp[0][i]=0, from[0][i]=1;
	
	FOR(i,N) {
		cin>>A[i];
		FOR(j,M+1) {
			if(j%2==0) dp[i+1][j]=dp[i][j]+A[i];
			else dp[i+1][j]=dp[i][j]-A[i];
		}
		FOR(j,M) {
			if(dp[i+1][j+1]<=dp[i+1][j]) {
				from[i+1][j+1]=1;
				dp[i+1][j+1]=dp[i+1][j];
			}
		}
	}
	vector<int> R;
	while(N||M) {
		if(from[N][M]==0) {
			N--;
		}
		else {
			R.push_back(N);
			M--;
		}
	}
	reverse(ALL(R));
	FORR(r,R) cout<<r<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
