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

int N,C,V;

ll A[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C>>V;
	for(i=1;i<=100000;i++) A[i]=1LL<<60;
	
	ll mi=1LL<<60;
	A[1]=0;
	for(i=1;i<=2*N;i++) {
		if(i>=N) mi=min(mi,A[i]);
		for(j=2*i;j<=2*N;j+=i) {
			A[j]=min(A[j],A[i]+C+1LL*(j/i-1)*V);	
		}
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
