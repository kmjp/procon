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
ll M,K;
const ll mo=1000000007;

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll P(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[N_-C_]*fact[N_]%mo;
}

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

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

void dfs(vector<int> V,Mat& A,int K) {
	int ma=*max_element(ALL(V))+1;
	if(V.size()==6) {
		if(V[0]==V[3]) return;
		if(V[1]==V[4]) return;
		if(V[2]==V[5]) return;
		if(V[3]==V[4]) return;
		if(V[4]==V[5]) return;
		int x=V[0]==V[2];
		int y=V[3]==V[5];
		
		if(x) A.v[y][x]+=P(K-2,ma-2);
		else A.v[y][x]+=P(K-3,ma-3);


	}
	else {
		int i;
		FOR(i,ma+1) {
			V.push_back(i);
			dfs(V,A,K);
			V.pop_back();
		}
		
	}
}

ll hoge(ll K) {
	Mat A;
	ll ret;
	if(N==1) {
		A.v[0][0]=K-1;
		A=powmat(M-1,A);
		ret=K*A.v[0][0]%mo;
	}
	else if(N==2) {
		A.v[0][0]=((K-2)*(K-2)+K-1)%mo;
		A=powmat(M-1,A);
		ret=K*(K-1)%mo*A.v[0][0]%mo;
	}
	else {
		dfs({0,1,0},A,K);
		dfs({0,1,2},A,K);
		int x,y;
		FOR(x,2) FOR(y,2) A.v[y][x]%=mo;
		
		A=powmat(M-1,A);
		ll XYX=K*(K-1)%mo;
		ll XYZ=K*(K-1)%mo*(K-2)%mo;
		ret=XYZ*(A.v[0][0]+A.v[1][0])+XYX*(A.v[0][1]+A.v[1][1]);
	}
	return ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M>>K;
	
	ll ret=0;
	for(i=1;i<=K;i++) {
		ll a=hoge(i)*comb(K,i)%mo;
		if((K-i)%2) {
			ret+=mo-a;
		}
		else {
			ret+=a;
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
