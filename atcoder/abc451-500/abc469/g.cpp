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

int K;

ll N;
int L;
string T;
string S[101];
int A[102];
int B[302];

const int MAT=203;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
ll mo;

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) cin>>S[i];
	cin>>N>>T;
	mo=L=T.size();
	FOR(i,K) {
		x=0;
		y=0;
		FORR(c,S[i]) {
			if(c=='a') {
				if(y==0) x++;
				else x--;
			}
			else {
				y=1-y;
			}
		}
		A[i]=(x%L+L)%L;
		B[i]=y;
	}
	for(i=K-1;i>=0;i--) {
		if(B[K]==0) {
			A[K]=(A[K]+A[i])%L;
			B[K]=B[i];
		}
		else {
			A[K]=(A[K]-A[i]+L)%L;
			B[K]=B[i]^1;
		}
	}
	
	Mat C;
	FOR(i,K+1) C.v[i][i]=1;
	
	for(y=K+1;y<=2*K+2;y++) {
		int turn=0;
		B[y]=B[y-(K+1)];
		for(i=1;i<=K;i++) {
			FOR(x,K+1) {
				if(turn==0) (C.v[y][x]+=C.v[y-i][x])%=mo;
				else (C.v[y][x]+=mo-C.v[y-i][x])%=mo;
			}
			turn^=B[y-i];
		}
	}
	FOR(y,K+1) FOR(x,K+1) C.v[y][x]=C.v[y+K+1][x];
	N--;
	C=powmat(N/(K+1),C,K+1);
	y=N%(K+1);
	ll ret=0;
	FOR(x,K+1) {
		(ret+=C.v[y][x]*A[x])%=mo;
	}
	rotate(T.begin(),T.begin()+(ret%mo),T.end());
	if(B[y]) reverse(ALL(T));
	cout<<T<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
