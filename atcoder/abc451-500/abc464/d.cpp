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
string S;
int X[202020],Y[202020];
ll dp[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) {
			dp[i][0]=dp[i][1]=-1LL<<60;
			cin>>X[i];
		}
		FOR(i,N-1) cin>>Y[i];
		if(S[N-1]=='S') {
			dp[N-1][0]=0;
			dp[N-1][1]=-X[N-1];
		}
		else {
			dp[N-1][1]=0;
			dp[N-1][0]=-X[N-1];
		}
		for(i=N-2;i>=0;i--) {
			FOR(x,2) FOR(y,2) {
				int p=-((S[i]=='S')!=(x==0))*X[i];
				if(x==1&&y==0) p+=Y[i];
				dp[i][x]=max(dp[i][x],dp[i+1][y]+p);
			}
		}
		cout<<max(dp[0][0],dp[0][1])<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
