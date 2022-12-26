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
ll A[101010];
ll L[101010];
ll R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	L[0]=A[0];
	for(i=1;i<=N-1;i++) L[i]=__gcd(L[i-1],A[i]);
	R[N-1]=A[N-1];
	for(i=N-2;i>=0;i--) R[i]=__gcd(R[i+1],A[i]);
	
	if(N==1) {
		cout<<A[0]+1<<endl;
		return;
	}
	
	FOR(i,N) {
		if(i==0) {
			if(A[0]%R[1]) {
				cout<<R[1]<<endl;
				return;
			}
		}
		else if(i==N-1) {
			if(A[i]%L[i-1]) {
				cout<<L[i-1]<<endl;
				return;
			}
		}
		else {
			ll v = __gcd(L[i-1],R[i+1]);
			if(A[i]%v) {
				cout<<v<<endl;
				return;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
