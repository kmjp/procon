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
int C[10];
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll p10[100];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		C[x]++;
	}
	
	p10[0]=1;
	FOR(i,90) p10[i+1]=p10[i]*10%mo;
	ll ret=0;
	for(i=1;i<=9;i++) if(C[i]) {
		C[i]--;
		ll pat=fact[N-1];
		FOR(j,10) (pat*=factr[C[j]])%=mo;
		(ret += i*pat%mo*p10[N-1])%=mo;
		FOR(j,10) if(C[j]) {
			C[j]--;
			ll pat=fact[N-2];
			FOR(x,10) (pat*=factr[C[x]])%=mo;
			FOR(x,N-1) (ret+=j*pat%mo*p10[x])%=mo;
			
			C[j]++;
		}
		C[i]++;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
