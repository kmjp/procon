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

int N,M;
int I[2][1000],S[1000];
int mat[100][100];
int V[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>I[0][i]>>I[1][i]>>S[i];
		mat[I[0][i]][I[1][i]]=S[i];
	}
	FOR(i,N) V[i]=i;
	
	int ma=0;
	do {
		int sc=0;
		
		FOR(x,N) FOR(y,x) sc+=mat[V[y]][V[x]];
		
		ma=max(ma,sc);
		
	} while(next_permutation(V,V+N));
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
