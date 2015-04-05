#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
ll A[2020000],B;
int nex[2020000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i], A[i+N]=A[i];
	
	while(Q--) {
		cin>>B;
		
		ll sum=0;
		x=0;
		FOR(i,N) {
			while(sum+A[x]<=B) sum+=A[x++];
			nex[i]=x;
			sum-=A[i];
			nex[i+N]=min(2*N,nex[i]+N);
		}
		
		for(x=j=0;x<N;j++) x=nex[x];
		for(i=x,x-=N,k=0;x<i;k++) x=nex[x];
		cout<<min(j,k)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
