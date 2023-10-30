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

const ll mo=998244353;
int N,M;

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

vector<ll> mult(vector<ll> A,vector<ll> B) {
	vector<ll> C(3);
	int a,b;
	FOR(a,3) FOR(b,3) (C[(a+b)%3]+=A[a]*B[b])%=mo;
	return C;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	ll ret=0;
	int a,b,c;
	for(a=0;a<=M;a++) for(b=0;a+b<=M;b++) {
		c=M-a-b;
		vector<ll> A={a,b,c},B={(2*b+c)%3==0,(2*b+c)%3==1,(2*b+c)%3==2};
		x=N;
		while(x) {
			if(x%2) B=mult(A,B);
			A=mult(A,A);
			x/=2;
		}
		ll v=(mo+B[0]-B[1])*fact[M]%mo*factr[a]%mo*factr[b]%mo*factr[c]%mo;
		(ret+=v)%=mo;
	}
	FOR(i,M) ret=ret*(mo+1)/3%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
