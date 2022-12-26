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

string S;
int N;
int P[26][101010];
int Q,L,R;
ll mo=1000000007;

const int NUM_=200003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,26) {
		FOR(x,N) {
			P[i][x+1]=P[i][x]+(S[x]=='a'+i);
		}
	}
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>Q;
	while(Q--) {
		cin>>L>>R;
		L--;
		int num[26]={},odd=0,sum=0;
		FOR(i,26) {
			num[i]=(P[i][R]-P[i][L])/2;
			sum+=num[i];
			if((P[i][R]-P[i][L])&1) odd++;
		}
		ll ret=odd?odd:1;
		(ret*=fact[sum])%=mo;
		FOR(i,26) {
			ret=ret*factr[num[i]]%mo;
		}
		cout<<ret<<endl;
		
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
