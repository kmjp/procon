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

int T;
ll N;
const ll mo=998244353;
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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


// 1 2 4 -1 -2 -4 -8

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	Mat A;
	A.v[0][0]=1; //x1
	A.v[0][2]=1; //x2
	A.v[0][3]=1; //x-1
	A.v[0][6]=1; //x-1
	A.v[0][5]=1; //x-2
	A.v[1][1]=1; //x1
	A.v[1][0]=1; //x2
	A.v[1][4]=1; //x-1
	A.v[1][3]=1; //x-2
	A.v[2][2]=1; //x1
	A.v[2][1]=1; //x2
	A.v[2][5]=1; //x-1
	A.v[2][4]=1; //x-2
	
	A.v[3][0]=1; //x1
	A.v[3][3]=1; //x-1
	A.v[4][1]=1; //x1
	A.v[4][0]=1; //x2
	A.v[4][4]=1; //x-1
	A.v[4][3]=1; //x-2
	A.v[5][2]=1; //x1
	A.v[5][1]=1; //x2
	A.v[5][5]=1; //x-1
	A.v[5][4]=1; //x-2
	
	A.v[6][6]=1;
	A.v[6][2]=1;
	A.v[6][5]=1;
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		auto p=powmat(N,A);
		
		// 1‚Æ-1‚¾‚¯‚ÌƒP[ƒX‚ğœ‚­
		ll ret=p.v[0][0]+mo-modpow(2,N-1);
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
