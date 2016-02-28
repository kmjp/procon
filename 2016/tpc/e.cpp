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
int A[101010];
int nex[101010][10];
int dist[101010],sel[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) cin>>A[i+2];
	N+=2;
	
	for(i=N-1;i>=0;i--) {
		dist[i]=10000000;
		FOR(x,10) {
			if(i==0 && x==0) continue;
			if(i>=N-2) nex[i][x]=N;
			else if(A[i+2]==x) nex[i][x]=i+2;
			else nex[i][x]=nex[i+1][x];
			
			if(dist[nex[i][x]]+1<dist[i]) dist[i]=dist[nex[i][x]]+1, sel[i]=x;
		}
	}
	
	x=0;
	while(x<N) {
		_P("%d",sel[x]);
		x=nex[x][sel[x]];
	}
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
