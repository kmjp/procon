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

ll S;
const ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

const int MAT=24;
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

ll hoge(int a,int b,int c,int d,int e,int f) {
	Mat A;
	vector<int> V={a,b,c,d,e,f};
	int i,j;
	FOR(i,6) {
		FOR(j,3) {
			A.v[(j+1)*6+i][j*6+i]=1;
		}
		if(V[i]) {
			FOR(j,i+1) A.v[i][(V[i]-1)*6+j]=1;
		}
	}
	A=powmat(S,A);
	ll ret=0;
	FOR(i,6) ret+=A.v[i][0];
	
	return ret%mo;
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>S;
	
	S-=6;
	ll ret=0;
	
	ret+=hoge(1,1,1,1,1,1);
	ret+=3*hoge(1,1,2,2,0,0);
	ret+=6*hoge(1,1,4,0,0,0);
	ret+=6*hoge(2,2,2,0,0,0);
	ret+=8*hoge(3,3,0,0,0,0);
	
	ret=ret%mo*modpow(24)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
