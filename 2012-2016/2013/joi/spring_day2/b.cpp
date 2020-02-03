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

int H,W,N;
int L,R,U,D;
ll mo=1000000007;
const int NUM_=400001;
ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll memo[3030][3030];

ll combi(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll hoge(int w,int h) {
	if(memo[w][h]>=0) return memo[w][h];
	
	ll ret=0;
	if(w==W && h==H) ret=1;
	if(w<W) ret += fact[h]*hoge(w+1,h);
	if(h<H) ret += fact[w]*hoge(w,h+1);
	return memo[w][h]=ret%mo;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	L=W+1;
	U=H+1;
	R=D=0;
	
	FOR(i,N) {
		cin>>y>>x;
		L=min(L,x);
		R=max(R,x);
		U=min(U,y);
		D=max(D,y);
	}
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	int num=(R-L+1)*(D-U+1);
	ll ret=1;
	for(i=1;i<=num-N;i++) ret=ret*i%mo;
	
	ret = ret*combi((W-R)+(L-1),(L-1))%mo*combi((H-D)+(U-1),(U-1))%mo;
	MINUS(memo);
	cout<<ret*hoge(R-L+1,D-U+1)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}