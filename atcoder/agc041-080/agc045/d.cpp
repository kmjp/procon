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

int N,A;
const ll mo=1000000007;

const int NUM_=10400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	ll ret=0;
	for(i=1;i<=A;i++) {
		int a,b,c;
		a=i;
		if(i==A) {
			b=N-i;
			c=0;
		}
		else {
			b=N-A;
			c=A-i-1;
		}
		
		ll sum=0;
		for(j=i-1;j>=0;j--) {
			ll pat=fact[a-j]*fact[(a-j)+b-1]%mo*factr[(a-j)-1]%mo;
			(pat*=fact[a]*factr[j]%mo*factr[a-j]%mo*fact[(a-j)+b+c]%mo*factr[(a-j)+b]%mo)%=mo;
			if(j&1) ret-=pat;
			else ret+=pat;
		}
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
