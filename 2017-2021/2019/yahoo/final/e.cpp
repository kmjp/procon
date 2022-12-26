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

int N,M;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

const int MAT=101;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
ll mo=1000000007;

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

ll comb(ll N_, ll C_) {
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll fdp[101],tdp[101];
Mat A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	comb(1,1);
	
	cin>>N>>M;
	for(i=1;i<=N/2;i++) {
		fdp[i]=comb(N,i)*comb(N-i,i)%mo*fact[i]%mo;
		FOR(j,N-2*i) fdp[i]=fdp[i]*(i+j)%mo;
	}
	
	for(i=1;i<=N/2;i++) { // cur
		for(j=0;j<i;j++) { //del
			ll pat=comb(i,j);
			FOR(x,j) pat=pat*(i-j+x)%mo;
			for(x=0;2*x+2*i<=N;x++) { //add
				ll pat2=pat*comb(N-2*i,x)%mo*comb(N-2*i-x,x)%mo*fact[x]%mo;
				int cand=x+2*i-j;
				FOR(y,N-2*i-2*x) {
					pat2=pat2*cand%mo;
					cand++;
				}
				(A.v[i][i-j+x] += pat2)%=mo;
			}
		}
	}
	auto B=powmat(M-2,A);
	FOR(x,N) FOR(y,N) (tdp[y]+=B.v[x][y]*fdp[x])%=mo;
	ll ret=0;
	FOR(x,N) if(tdp[x]) {
		ll pat=fact[x-1]*tdp[x]%mo;
		int cand=x;
		FOR(y,N-2*x) {
			pat=pat*cand%mo;
			cand++;
		}
		ret+=pat;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
