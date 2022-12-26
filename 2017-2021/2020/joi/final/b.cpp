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

int N,K;
string S;
int A[202020];
int B[202020];
int C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) {
		A[i+1]=A[i];
		B[i+1]=B[i];
		C[i+1]=C[i];
		if(S[i]=='J') A[i+1]++;
		if(S[i]=='O') B[i+1]++;
		if(S[i]=='I') C[i+1]++;
	}
	
	int mi=1010101;
	FOR(i,N) {
		x=lower_bound(A+i,A+N+1,A[i]+K)-A;
		x=lower_bound(B+x,B+N+1,B[x]+K)-B;
		x=lower_bound(C+x,C+N+1,C[x]+K)-C;
		if(x<N+1) mi=min(mi,x-(i+3*K));
	}
	
	if(mi>1000000) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
