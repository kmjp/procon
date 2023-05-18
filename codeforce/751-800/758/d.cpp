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


int N;
string S;
const ll mo=998244353;
int num[3][3];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int isb=0,isw=0;
	FOR(i,N) {
		cin>>S;
		if(S[1]=='B') S[1]='W';
		else if(S[1]=='W') S[1]='B';
		
		FORR(c,S) {
			if(c=='B') c=0,isb++;
			if(c=='W') c=1,isw++;
			if(c=='?') c=2;
		}
		num[S[0]][S[1]]++;
	}
	ll ret=0;
	// all b
	if(isw==0) ret++;
	// all w
	if(isb==0) ret++;
	
	for(int nb=1;nb<=N-1;nb++) {
		int b1=num[0][0]+num[0][1]+num[0][2];
		int w1=num[1][0]+num[1][1]+num[1][2];
		int b2=num[0][0]+num[1][0]+num[2][0];
		int w2=num[0][1]+num[1][1]+num[2][1];
		
		(ret+=comb(N-b1-w1,nb-b1)*comb(N-b2-w2,nb-b2))%=mo;
		
		// ALL B+ALL C
		if(num[0][1]||num[1][0]) continue;
		int lb=nb-num[0][0]-num[0][2]-num[2][0];
		int lw=N-nb-num[1][1]-num[1][2]-num[2][1];
		(ret+=mo-comb(lb+lw,lb))%=mo;
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}