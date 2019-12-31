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

int N,L,W;
int A[100001],B[100001];
int F[100001],DP[100001];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N>>L>>W;
	
	FOR(i,N) {
		cin>>A[i]>>B[i];
		F[i]=B[i];
		DP[i]=1000000;
	}
	F[0]=DP[0]=x=0;
	for(i=1;i<N;i++) {
		while(x<i && (B[x]<A[i]-W || DP[x]>=1000000)) x++;
		if(x==i || F[x]+W>B[i]) continue;
		F[i]=max(A[i],F[x]+W);
		DP[i]=DP[x]+1;
	}
	
	if(DP[N-1]>=1000000) DP[N-1]=-1;
	cout << DP[N-1] << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


