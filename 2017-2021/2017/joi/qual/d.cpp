#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int A[101010];
int S[101010][20];
int num[20];

int dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		FOR(j,M) S[i+1][j]=S[i][j]+(A[i]==j);
	}
	FOR(i,M) num[i]=S[N][i];
	
	FOR(i,1<<M) dp[i]=10101010;
	dp[0]=0;
	for(int mask=0;mask<1<<M;mask++) {
		int tot=0;
		FOR(i,M) if(mask&(1<<i)) tot+=num[i];
		FOR(i,M) if((mask&(1<<i))==0) {
			int dif=num[i]-(S[tot+num[i]][i]-S[tot][i]);
			dp[mask|(1<<i)]=min(dp[mask|(1<<i)],dp[mask]+dif);
		}
	}
	
	cout<<dp[(1<<M)-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
