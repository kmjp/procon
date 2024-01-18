#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,K;
ll A[1010101];
const ll mo=998244353;
ll dp[1010101];
int ok[1010101];

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;

	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	reverse(A,A+N);
	if(A[0]-A[1]>K) dp[1]=1;
	for(i=1;i<N;i++) {
		if(i) ok[i]=ok[i-1];
		while(ok[i]<N&&A[i]-A[ok[i]]<=K) ok[i]++;
		int conf=ok[i]-i-1;
		
		//先頭以外ならどこでも
		(dp[i+1]+=dp[i]*i)%=mo;
		
		//先頭に置くなら、ぶつかる奴は後ろに置く
		(dp[i+conf+1]+=dp[i]*fact[i+conf+1-2]%mo*factr[i-1])%=mo;
	}
	cout<<dp[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
