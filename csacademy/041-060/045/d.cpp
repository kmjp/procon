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

int N,M,K;
ll mat[303][303];
int ok[303][303],direct[303][303];
ll dp[303][303];
ll ma[303][303],pat[303][303];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M>>K;
	FOR(x,N) FOR(y,N) mat[x][y]=(x==y)?0:1LL<<60;
	FOR(i,M) {
		cin>>x>>y>>r;
		mat[x-1][y-1]=mat[y-1][x-1]=r;
		direct[x-1][y-1]=direct[y-1][x-1]=r;
	}
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
	
	FOR(x,N) FOR(y,N) ok[x][y]=(mat[0][x]+mat[x][y]+mat[y][N-1]==mat[0][N-1]);
	FOR(x,N) {
		dp[x][x]=1;
		vector<pair<ll,int>> V;
		FOR(y,N) V.push_back({mat[x][y],y});
		sort(ALL(V));
		FORR(v,V) {
			y=v.second;
			FOR(z,N) if(mat[x][z]+mat[z][y]==mat[x][y] && direct[y][z]==mat[y][z] && y!=z) dp[x][y]+=dp[x][z];
		}
	}
	
	ma[0][0]=pat[0][0]=1;
	ma[1][0]=pat[1][0]=1;
	FOR(i,K) {
		FOR(x,N) FOR(y,N) if(mat[0][x]+mat[x][y]==mat[0][y] && mat[x][y]>0) {
			if(ma[i+1][y]<ma[i][x]*dp[x][y]) {
				ma[i+1][y]=ma[i][x]*dp[x][y];
				pat[i+1][y]=0;
			}
			if(ma[i+1][y]==ma[i][x]*dp[x][y]) {
				(pat[i+1][y]+=pat[i][x])%=mo;
			}
		}
	}
	
	ll ret=0,ret2=0;
	FOR(i,N) if(mat[0][i]+mat[i][N-1]==mat[0][N-1] && ma[K][i]>0) {
		if(ret<ma[K][i]*dp[i][N-1]) {
			ret=ma[K][i]*dp[i][N-1];
			ret2=0;
		}
		if(ret==ma[K][i]*dp[i][N-1]) {
			ret2 += pat[K][i];
		}
	}
	
	cout<<ret<<" "<<ret2%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
