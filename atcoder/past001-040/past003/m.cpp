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
vector<int> E[101010];
vector<int> C;
int D[101010][17];
int dp[1<<17][17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>x;
	C.push_back(x-1);
	cin>>x;
	FOR(j,x) {
		cin>>y;
		C.push_back(y-1);
	}
	FOR(i,C.size()) {
		FOR(j,N) D[j][i]=1<<20;
		queue<int> Q;
		D[C[i]][i]=0;
		Q.push(C[i]);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(D[e][i]>D[x][i]+1) {
				D[e][i]=D[x][i]+1;
				Q.push(e);
			}
		}
	}
	int mask;
	FOR(mask,1<<C.size()) FOR(x,C.size()) dp[mask][x]=1<<30;
	dp[1][0]=0;
	FOR(mask,1<<C.size()) FOR(i,C.size()) if(dp[mask][i]<1<<30) {
		FOR(j,C.size()) if(i!=j) {
			dp[mask|(1<<j)][j]=min(dp[mask|(1<<j)][j],dp[mask][i]+D[C[j]][i]);
		}
	}
	
	int ret=1<<30;
	FOR(i,C.size()) ret=min(ret,dp[(1<<C.size())-1][i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
