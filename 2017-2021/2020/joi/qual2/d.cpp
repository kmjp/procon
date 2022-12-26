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

int X[10],Y[10];
int D[10][10];

int M,R;
int dp[101010][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=9;i++) {
		Y[i]=(i+2)/3;
		X[i]=(i-1)%3;
	}
	FOR(x,10) FOR(y,10) D[x][y]=abs(X[x]-X[y])+abs(Y[x]-Y[y])+1;
	cin>>M>>R;
	FOR(x,M) FOR(y,10) dp[x][y]=1<<30;
	dp[0][0]=0;
	priority_queue<pair<int,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		int cur=Q.top().second/10;
		int pos=Q.top().second%10;
		int co=-Q.top().first;
		Q.pop();
		if(dp[cur][pos]!=co) continue;
		if(cur==R) {
			cout<<co<<endl;
			return;
		}
		
		FOR(x,10) {
			y=co+D[pos][x];
			j=(cur*10+x)%M;
			if(dp[j][x]>y) {
				dp[j][x]=y;
				Q.push({-y,j*10+x});
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
