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

ll N,M;
ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll fib(ll k,ll a1=1,ll a2=1) {
	ll R[2][2]={{1,0},{0,1}};
	ll A[2][2]={{1,1},{1,0}};
	k--;
	
	while(k) {
		ll S[2][2], T[2][2];
		if(k%2) {
			S[0][0]=(A[0][0]*R[0][0]+A[0][1]*R[1][0])%mo;
			S[0][1]=(A[0][0]*R[0][1]+A[0][1]*R[1][1])%mo;
			S[1][0]=(A[1][0]*R[0][0]+A[1][1]*R[1][0])%mo;
			S[1][1]=(A[1][0]*R[0][1]+A[1][1]*R[1][1])%mo;
			swap(S,R);
		}
		T[0][0]=(A[0][0]*A[0][0]+A[0][1]*A[1][0])%mo;
		T[0][1]=(A[0][0]*A[0][1]+A[0][1]*A[1][1])%mo;
		T[1][0]=(A[1][0]*A[0][0]+A[1][1]*A[1][0])%mo;
		T[1][1]=(A[1][0]*A[0][1]+A[1][1]*A[1][1])%mo;
		swap(T,A);
		k>>=1;
	}
	return (R[1][0]+R[1][1])%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	M+=2*(N-1);
	ll F=fib(M);
	
	ll a=1,b=1,c=1;
	ll M1=M-1,M2=M1;
	for(i=1;i<N;i++) {
		F=(F+mo-b*modpow(a*c%mo)%mo)%mo;
		
		(a*=M1)%=mo;
		M1=(M1+mo-1)%mo;
		(b*=M2)%=mo;
		M2=(M2+mo-1)%mo;
		(b*=M2)%=mo;
		M2=(M2+mo-1)%mo;
		(c*=i)%=mo;
	}
	cout<<F<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
