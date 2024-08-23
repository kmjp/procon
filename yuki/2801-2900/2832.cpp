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

const int MAT=121;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

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

int N,M,X;
int C[10][10];
int S[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		C[x][y]++;
		C[y][x]++;
		S[x]++;
		S[y]++;
		if(x==y) C[x][x]--,S[x]--;
	}
	
	Mat A;
	FOR(i,11) FOR(j,N) {
		
		if(S[j]==0) {
			A.v[j*10+10][j*10+10]=1;
		}
		else if(S[j]==1) {
			FOR(k,N) if(C[j][k]) {
				A.v[k*11+j][j*11+10]=1;
				A.v[j*11+10][j*11+k]=1;
			}
		}
		else {
			FOR(k,N) if(C[j][k]) {
				if(i==10) A.v[k*11+j][j*11+i]=C[j][k]*modpow(S[j])%mo;
				else A.v[k*11+j][j*11+i]=(C[j][k]-(i==k))*modpow(S[j]-1)%mo;
			}
		}
	}
	A=powmat(X,A);
	FOR(i,N) {
		ll ret=0;
		FOR(j,11) ret+=A.v[i*11+j][10];
		cout<<ret%mo<<endl;
	}
	
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
