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

ll N;
ll mo=1000000007;

ll fib(ll k,ll a1=1,ll a2=1) {
	if(k==0) return 0;
	if(k==1) return a1;
	if(k==2) return a2;
	k-=2;
	ll R[2][2]={{1,0},{0,1}};
	ll A[2][2]={{1,1},{1,0}};
	
	while(k) {
		if(k%2) {
			ll S[2][2];
			S[0][0]=(A[0][0]*R[0][0]+A[0][1]*R[1][0])%mo;
			S[0][1]=(A[0][0]*R[0][1]+A[0][1]*R[1][1])%mo;
			S[1][0]=(A[1][0]*R[0][0]+A[1][1]*R[1][0])%mo;
			S[1][1]=(A[1][0]*R[0][1]+A[1][1]*R[1][1])%mo;
			swap(S,R);
		}
		ll T[2][2];
		T[0][0]=(A[0][0]*A[0][0]+A[0][1]*A[1][0])%mo;
		T[0][1]=(A[0][0]*A[0][1]+A[0][1]*A[1][1])%mo;
		T[1][0]=(A[1][0]*A[0][0]+A[1][1]*A[1][0])%mo;
		T[1][1]=(A[1][0]*A[0][1]+A[1][1]*A[1][1])%mo;
		swap(T,A);
		k>>=1;
	}
	return (R[0][0]+R[0][1])%mo;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	if(N==0) return _P("0\n");
	mo=(1000000007+1)*2;
	ll M=fib(N,1,1);
	mo=1000000007;
	ll L=fib(M,1,1);
	cout<<L<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
