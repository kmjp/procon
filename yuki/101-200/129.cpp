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

ll N,M;
ll C[10001][10001];
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	N/=1000;
	ll R=N%M;
	
	FOR(i,10001) {
		C[i][i]=C[i][0]=1;
		for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%1000000000;
	}
	cout<<C[M][R]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
