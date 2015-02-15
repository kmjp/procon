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

int N;
int A[70];
ll mo=1000000007;
ll memo[70][100000];

ll dfs(int d,int c) {
	if(d>=69) return 1;
	if(memo[d][c]>=0) return memo[d][c];
	int x;
	memo[d][c]=0;
	FOR(x,10) if(x<=c+A[d]) {
		memo[d][c]+=dfs(d+1,(c+A[d]-x)/10);
	}
	memo[d][c]%=mo;
	return memo[d][c];
	
}

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	MINUS(memo);
	cout << (dfs(0,0)+(mo-1))%mo << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


