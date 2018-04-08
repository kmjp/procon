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

int N,W,H;
int C[101][101];
int L[1010],R[1010],U[1010],D[1010];
int mat[1010][1010];
int in[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>H;
	
	FOR(i,N+1) L[i]=W+1,R[i]=-1,U[i]=H+1,D[i]=-1;
	
	FOR(y,H) FOR(x,W) {
		cin>>C[y][x];
		L[C[y][x]]=min(L[C[y][x]],x);
		R[C[y][x]]=max(R[C[y][x]],x);
		U[C[y][x]]=min(U[C[y][x]],y);
		D[C[y][x]]=max(D[C[y][x]],y);
	}
	
	for(i=1;i<=N;i++) if(R[i]>=0) {
		for(y=U[i];y<=D[i];y++) for(x=L[i];x<=R[i];x++) mat[i][C[y][x]]=1;
		mat[i][i]=0;
	}
	for(x=1;x<=N;x++) {
		for(y=1;y<=N;y++) if(mat[x][y]) in[y]++;
	}
	queue<int> Q;
	for(x=1;x<=N;x++) if(in[x]==0) Q.push(x);
	i=N;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		cout<<x;
		if(--i) cout<<" ";
		for(y=1;y<=N;y++) if(mat[x][y]) {
			if(--in[y]==0) Q.push(y);
		}
		
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
