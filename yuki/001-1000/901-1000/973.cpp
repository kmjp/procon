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
ll X,A[5050];
int memo[5050][5050];
int L[5050],R[5050];
int Rs[5050][5050];
int Ls[5050][5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N+1) {
		L[i]=R[i]=i;
		ll sum=0;
		for(j=i;j<N;j++) {
			sum+=A[j];
			if(sum<=X) R[i]=j+1;
		}
		sum=0;
		
		for(j=i-1;j>=0;j--) {
			sum+=A[j];
			if(sum<=X) L[i]=j;
		}
	}
	FOR(i,N) Ls[i][i+1]=Rs[i][i+1]=1;
	
	for(int len=2;len<=N;len++) {
		for(x=0;x+len<=N;x++) {
			y=Rs[x+1][x+len]-Rs[R[x]+1][x+len];
			y+=Ls[x][x+len-1]-Ls[x][L[x+len]-1];
			memo[x][x+len]=y>0;
			Ls[x][x+len]=Ls[x][x+len-1]+(y==0);
			Rs[x][x+len]=Rs[x+1][x+len]+(y==0);
		}
	}
	
	if(memo[0][N]) cout<<"A"<<endl;
	else cout<<"B"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
