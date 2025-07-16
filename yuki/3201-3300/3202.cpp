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

string S;
ll K;
int N;
const ll mo=1000000007;

const int MAT=7;
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



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	
	Mat A[2],B;
	FOR(i,7) A[0].v[i][i]=A[1].v[i][i]=B.v[i][i]=1;
	// 10,L0,L^20,11,L1,L^21,1
	//êVãK
	A[0].v[0][6]=1;
	A[0].v[1][6]=1;
	A[0].v[2][6]=1;
	A[1].v[3][6]=1;
	A[1].v[4][6]=1;
	A[1].v[5][6]=1;
	//1èIÇÌÇËÇÃÇ‡ÇÃÇ…0í«â¡
	A[0].v[0][3]=1;
	A[0].v[1][4]=1;
	A[0].v[1][3]=1;
	A[0].v[2][5]=1;
	A[0].v[2][4]=2;
	A[0].v[2][3]=1;
	A[1].v[3][0]=1;
	A[1].v[4][1]=1;
	A[1].v[4][0]=1;
	A[1].v[5][2]=1;
	A[1].v[5][1]=2;
	A[1].v[5][0]=1;
	FORR(c,S) {
		B=mulmat(B,A[c-'0']);
	}
	B=powmat(K,B);
	cout<<(B.v[2][6]+B.v[5][6])%mo<<endl;
		
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
