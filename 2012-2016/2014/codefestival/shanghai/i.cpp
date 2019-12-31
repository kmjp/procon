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


int N;
string S[1001];
int num[1001][1001],vis[1001][1001];

void solve() {
	int i,j,k,l,r,x,y,x2,y2; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[y];
	
	num[N-1][N-1]=2;
	vis[N-1][N-1]=1;
	queue<int> Q;
	Q.push((N-1)*1000+(N-1));
	
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		int cy=k/1000,cx=k%1000;
		FOR(i,4) {
			int dd[4]={0,1,0,-1};
			int ty=cy+dd[i],tx=cx+dd[i^1];
			if(tx<0||ty<0||tx>=N||ty>=N) continue;
			if(vis[ty][tx]) continue;
			num[ty][tx]++;
			if(S[cy][cx]=='#') num[ty][tx]+=2;
			
			if(num[ty][tx]>=2) vis[ty][tx]=1, Q.push(ty*1000+tx);
		}
	}
	
	if(vis[0][0]) _P("YES\n");
	else _P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
