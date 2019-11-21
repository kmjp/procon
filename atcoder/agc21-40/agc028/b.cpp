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
int A[101010];
ll S[101010];
ll mo=1000000007;

const int NUM_=400001;
ll fact[NUM_+1],inv[NUM_+1];
ll invsum[NUM_+1];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=invsum[1]=1;
	for (int i=2;i<=NUM_;++i) {
		inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		(invsum[i] = invsum[i-1] + inv[i])%=mo;
	}
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		(ret+=(invsum[i+1]+invsum[N-i]-1)*A[i])%=mo;
	}
	
	cout<<ret*fact[N]%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
