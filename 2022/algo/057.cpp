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
const ll mo=1000000007;

const int MAT=16;
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

int K;
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	
	Mat V;
	if(K==2) {
		V.v[0][0]=1;
		V.v[1][0]=1;
		V.v[0][1]=1;
	}
	else if(K==3) {
		V.v[1][0]=1;
		V.v[4][0]=1;
		V.v[7][0]=1;
		V.v[0][1]=1;
		V.v[6][1]=1;
		V.v[4][3]=1;
		V.v[0][4]=1;
		V.v[3][4]=1;
		V.v[1][6]=1;
		V.v[0][7]=1;
	}
	else {
		V.v[0][0]=V.v[3][0]=V.v[9][0]=V.v[12][0]=V.v[15][0]=1;
		V.v[0][3]=V.v[12][3]=1;
		V.v[9][6]=1;
		V.v[0][9]=V.v[6][9]=1;
		V.v[0][12]=V.v[3][12]=1;
		V.v[0][15]=1;
	}
	
	
	V=powmat(N,V,16);
	cout<<V.v[0][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
