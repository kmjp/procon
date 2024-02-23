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

ll N,K;
const ll mo=998244353;

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


ll B[51][51]; //B(n,m) := n個のm種類の整数の並べ方
ll P[55][55]; //P(L,R) := 小さいものL個、大きいものR個選んだ時の中央値の総和

const int MAT=102;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};}; //

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
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	B[0][0]=1;
	FOR(x,50) FOR(y,50) {
		for(k=1;x+k<=50;k++) {
			(B[x+k][y+1]+=B[x][y]*hcomb(x+1,k))%=mo;
		}
	}
	cin>>N>>K;
	
	for(x=0;x<N;x++) {
		// x個les, 1個same、y個more、1個sum、1個定数
		Mat A;
		FOR(i,x) {
			A.v[2*i][2*i]++;
			A.v[2*i+1][2*i]++;
			A.v[2*i+2][2*i]++;
			A.v[2*i+3][2*i]++;
			A.v[2*i+1][2*i+1]++;
			A.v[2*i+3][2*i+1]++;
		}
		A.v[2*x][2*x]++;
		A.v[2*x+1][2*x]++;
		A.v[2*x+3][2*x]++;
		A.v[2*x+1][2*x+1]++;
		A.v[2*x+3][2*x+1]++;
		FOR(i,N-x) {
			A.v[2*(x+1+i)+1][2*(x+1+i)+1]++;
			A.v[2*(x+1+i)+3][2*(x+1+i)+1]++;
		}
		
		A=powmat(K,A,102);
		for(y=0;x+y<N;y++) P[x][y]=A.v[2*(x+1+y)+1][0];
	}
	
	ll ret=0;
	for(int le=0;le<=N;le++) for(int mor=0;le+mor<N;mor++) {
		int same=N-1-le-mor;
		for(int lep=0;lep<=le;lep++) for(int mop=0;mop<=mor;mop++) {
			ll p=B[le][lep]*B[mor][mop]%mo;
			if(p==0) continue;
			for(int lefle=0;lefle<=le;lefle++) for(int rimo=lefle+1;rimo<=mor;rimo++) {
				ll arrange=comb(lefle+mor-rimo,lefle)*comb(rimo+le-lefle,rimo)%mo;
				ll s=P[lep][mop];
				ll c=hcomb(N-same+1,same);
				ret+=p*arrange%mo*s%mo*c%mo;
			}
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
