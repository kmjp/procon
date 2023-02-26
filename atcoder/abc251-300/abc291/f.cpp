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

int N,M;
string S[101010];
int D[2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>S[i];
		FORR(c,S[i]) c-='0';
		D[0][i]=D[1][i]=1<<20;
	}
	
	D[0][0]=0;
	FOR(i,N) {
		FOR(j,M) if(S[i][j]) chmin(D[0][i+j+1],D[0][i]+1);
	}
	D[1][N-1]=0;
	for(i=N-1;i>=0;i--) {
		FOR(j,M) if(S[i][j]) chmin(D[1][i],D[1][i+j+1]+1);
	}
	
	for(k=1;k<=N-2;k++) {
		int mi=1<<20;
		for(x=max(0,k-M);x<k;x++) for(y=k+1;y<=min(k+M,N-1);y++) if(y-x<=M&&S[x][y-x-1]) mi=min(mi,D[0][x]+D[1][y]+1);
		if(mi==1<<20) mi=-1;
		cout<<mi<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
