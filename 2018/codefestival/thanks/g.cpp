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

int N,K;
int A[5050],B[5050];
int P[5050];
int vis[5050];

int from[5050],to[5050],dp[5050];
int tdp[5050][5050][2];

void hoge(vector<int> V) {
	int i,x,y;
	int M=V.size();
	FOR(i,M+1) dp[i]=-1<<30;
	
	if(M==1) {
		dp[1]=V[0];
		return;
	}
	V.push_back(V[0]);
	
	FOR(i,2) {
		FOR(x,M+1) FOR(y,M+1) tdp[x][y][0]=tdp[x][y][1]=-1<<30;
		
		if(i==0) tdp[0][1][1]=V[1];
		if(i==1) tdp[0][1][0]=V[0];
		
		for(x=1;x<M;x++) {
			for(y=1;y<M;y++) {
				tdp[x][y][0]=max(tdp[x][y][0],tdp[x-1][y][1]+V[x]);
				tdp[x][y+1][0]=max(tdp[x][y+1][0],tdp[x-1][y][0]+V[x]);
				tdp[x][y+(x<M-1||i==0)][1]=max(tdp[x][y+(x<M-1||i==0)][1],tdp[x-1][y][1]+V[x+1]);
				tdp[x][y+(x<M-1||i==0)][1]=max(tdp[x][y+(x<M-1||i==0)][1],tdp[x-1][y][0]+V[x+1]);
			}
		}
		for(x=1;x<=M;x++) dp[x]=max({dp[x],tdp[M-1][x][0],tdp[M-1][x][1]});
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		P[A[i]]=B[i];
	}
	
	FOR(x,5005) from[x]=-1<<30;
	from[0]=0;
	int cur=0;
	
	for(i=1;i<=N;i++) if(vis[i]==0) {
		vector<int> V;
		V.push_back(i);
		x=P[i];
		while(x!=i) {
			V.push_back(x);
			x=P[x];
		}
		FORR(v,V) vis[v]=1;
		
		hoge(V);
		
		FOR(x,5050) to[x]=-1<<30;
		
		FOR(x,cur+1) FOR(y,V.size()+1) to[x+y]=max(to[x+y],from[x]+dp[y]);
		cur+=V.size();
		swap(from,to);
	}
	
	int ret=0;
	for(i=K;i<=N;i++) ret=max(ret,from[i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
