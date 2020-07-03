#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,C,VV;
int S[2001],T[2001],Y[2001],M[2001];
vector<int> V[2001];

int dp[52][301];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>C>>VV;
	FOR(i,VV) cin>>S[i], S[i]--, V[S[i]].push_back(i);
	FOR(i,VV) cin>>T[i], T[i]--;
	FOR(i,VV) cin>>Y[i];
	FOR(i,VV) cin>>M[i];
	FOR(i,N+1) FOR(j,C+1) dp[i][j]=1<<29;
	dp[0][C]=0;
	priority_queue<pair<int,int> > Q;
	Q.push(make_pair(0, C));
	while(Q.size()) {
		pair<int,int> p = Q.top();
		Q.pop();
		x=p.second/10000, y=p.second%10000;
		if(dp[x][y]!=p.first) continue;
		FOR(i,V[x].size()) {
			if(Y[V[x][i]]>y) continue;
			if(dp[T[V[x][i]]][y-Y[V[x][i]]] > p.first + M[V[x][i]]) {
				dp[T[V[x][i]]][y-Y[V[x][i]]] = p.first + M[V[x][i]];
				Q.push(make_pair(dp[T[V[x][i]]][y-Y[V[x][i]]], T[V[x][i]]*10000+(y-Y[V[x][i]])));
			}
		}
	}
	
	int mi=1<<29;
	FOR(i,C+1) mi=min(mi,dp[N-1][i]);
	if(mi==1<<29) _P("-1\n");
	else _P("%d\n", mi);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
