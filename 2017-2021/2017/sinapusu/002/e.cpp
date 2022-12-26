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

int X[3][4],P[3][4];
int N;
int A,B,C;

int hoge(int a,int b,int c) {
	int tot=100;
	int i;
	FOR(i,4) if(a<X[0][i]) break;
	if(i>=1) tot+=P[0][i-1];
	FOR(i,4) if(b<X[1][i]) break;
	if(i>=1) tot+=P[1][i-1];
	FOR(i,4) if(c<X[2][i]) break;
	if(i>=1) tot+=P[2][i-1];
	return tot;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) FOR(j,4) cin>>X[i][j]>>P[i][j];
	cin>>N;
	FOR(i,N) {
		cin>>A>>B>>C;
		int mi=1<<20;
		mi=min(mi,hoge(A,B,C));
		mi=min(mi,hoge(A,C,B));
		mi=min(mi,hoge(B,A,C));
		mi=min(mi,hoge(B,C,A));
		mi=min(mi,hoge(C,B,A));
		mi=min(mi,hoge(C,A,B));
		cout<<mi<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
