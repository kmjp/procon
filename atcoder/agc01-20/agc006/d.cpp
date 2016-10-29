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

int N;
int A[202020];
int B[202020];

int ok(int cur) {
	if(cur>2*N-1) return 0;
	
	int i;
	FOR(i,2*N-1) B[i]=A[i]>=cur;
	int L=N-1,R=N-1;
	while(L>0 && B[L]!=B[L-1]) L--;
	while(R<2*N-1 && B[R]!=B[R+1]) R++;
	return ((N-1)-L<=R-(N-1))?B[L]:B[R];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N-1) cin>>A[i];
	int cur=1;
	for(i=20;i>=0;i--) if(ok(cur+(1<<i))) cur+=1<<i;
	cout<<cur<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
