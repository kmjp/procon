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

int N;
string S[2002];
ll mo=1000000007;
int cost[2020][2020];
ll ret[2020];
ll dp[2020];

const int CN=4001;
ll C[CN][CN];
ll fact[CN];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	FOR(i,2020) fact[i+1]=fact[i]*(i+1)%mo;
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	
	sort(S,S+N);
	FOR(y,N) {
		cost[y][y]=cost[y][N]=cost[N][y]=1;
		FOR(x,y) {
			cost[x][y]=1;
			while(cost[x][y]<=S[x].size() && cost[x][y]<=S[y].size() && S[x][cost[x][y]-1]==S[y][cost[x][y]-1]) cost[x][y]++;
			cost[y][x]=cost[x][y];
		}
	}
	
	FOR(y,N) for(x=y+1;x<=N;x++) (ret[x]+=cost[y][y+1]*C[N-(y+1)][x-(y+1)]%mo*fact[x])%=mo;
	
	FOR(x,N) for(y=x+1;y<N;y++) dp[y-x]+=max(cost[x][y],cost[y][y+1]);
	for(i=1;i<=N-1;i++) for(x=i;x<=N;x++) (ret[x]+=dp[i]*C[N-(i+1)][x-i]%mo*fact[x])%=mo;
	
	for(i=1;i<=N;i++) cout<<ret[i]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
