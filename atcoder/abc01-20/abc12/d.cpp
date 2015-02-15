#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M;
int mat[1000][1000];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N>>M;
	FOR(x,1000) FOR(y,1000) mat[x][y]=1<<25;
	FOR(x,1000) mat[x][x]=0;
	FOR(i,M) {
		cin>>x>>y>>j;
		mat[x-1][y-1]=mat[y-1][x-1]=j;
	}
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	
	int mi=10000000;
	FOR(i,N) {
		x=0;
		FOR(j,N) x=max(x,mat[i][j]);
		mi=min(x,mi);
	}
	cout << mi << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


