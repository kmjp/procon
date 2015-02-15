#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M,D;
int A[32][1000001];
int B[32][1000001];
int rev[1000001];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N>>M>>D;
	
	FOR(i,N) A[0][i]=B[0][i]=i;
	while(M--) {
		cin>>x;
		swap(A[0][x-1],A[0][x]);
	}
	
	FOR(i,30) FOR(x,N) A[i+1][x]=A[i][A[i][x]];
	FOR(i,30) {
		if(D&(1<<i)) {
			FOR(x,N) B[i+1][x]=A[i][B[i][x]];
		}
		else {
			FOR(x,N) B[i+1][x]=B[i][x];
		}
	}
	
	
	FOR(i,N) rev[B[30][i]]=i;
	FOR(i,N) _P("%d\n",rev[i]+1);
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


