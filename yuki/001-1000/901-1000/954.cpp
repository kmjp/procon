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

set<int> S;
ll A[101];
ll V[5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A[0]=1;
	A[1]=1;
	for(i=2;i<=100;i++) {
		A[i]=A[i-1]+A[i-2];
		if(A[i-1]<0 || A[i-2]<0) A[i]=-1;
		if(A[i]>1LL<<59) A[i]=-1;
	}
	
	FOR(i,5) cin>>V[4-i];
	
	int ma=0;
	FOR(i,95) {
		FOR(j,5) if(A[i+j]!=V[j]) break;
		ma=max(ma,j);
	}
	
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
