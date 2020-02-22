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
ll A[1202020];
ll mo=998244353;
ll S[1202020];
ll S2[1202020];

const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

vector<int> D[1010101];
ll ret;
ll T[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		//x=1LL*rand()*rand()%1000000;
		A[x]++;
	}
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	ll ret=0;
	for(i=1;i<=1000000;i++) {
		(ret+=A[i]*(A[i]-1)/2%mo*i)%=mo;
		for(j=i;j<=1000000;j+=i) {
			(S2[i]+=(A[j]*j)%mo*S[i])%=mo;
			(S[i]+=A[j]*j)%=mo;
		}
	}
	for(i=1000000;i>=1;i--) {
		for(j=2*i;j<=1000000;j+=i) S2[i]+=mo-S2[j];
		S2[i]%=mo;
		(ret+=S2[i]*inv[i])%=mo;
	}
	
	
	
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
