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

int N,K;
int A[202];

ll dp[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
	}
	
	int mask;
	FOR(mask,1<<K) dp[mask]=1LL<<60;
	dp[0]=0;
	FOR(i,N) {
		j=A[i];
		FOR(mask,1<<K) if((mask&(1<<j))==0&&dp[mask]<1LL<<59) {
			x=__builtin_popcount(mask);
			int add=0;
			FOR(y,K) if(y>j&&(mask&(1<<y))) add++;
			
			if(x<(K-1)/2) add-=i-(x-(K-1)/2);
			if(x==(K-1)/2&&K%2==0) add-=i;
			if(x>(K-1)/2) add+=i-(x-(K-1)/2);
			dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+add);
		}
	}
	cout<<dp[(1<<K)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
