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

ll N;
const ll mo=998244353;
ll p10[20];

const int MAT=3;
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
	
	cin>>N;
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	ll ret=0;
	ll dig=1;
	for(int d=1;p10[d-1]<=N;d++) {
		ll p=p10[d]%mo; //Œ…”
		ll L=p10[d-1];
		ll R=min(p10[d],N+1);
		
		FOR(i,50) {
			if(L==R) break;
			if(i>=24&&(R-L)%24==0) break;
			ret=(ret*dig%mo*p%mo+L%mo*dig+ret)%mo;
			dig=dig*p%mo*dig%mo;
			L++;
		}
		if(L==R) continue;
		Mat A;
		A.v[0][0]=A.v[1][1]=A.v[2][2]=1;
		ll v=dig;
		FOR(i,24) {
			Mat B;
			B.v[0][0]=(dig*p+1)%mo;
			B.v[0][1]=dig;
			B.v[1][1]=B.v[1][2]=B.v[2][2]=1;
			A=mulmat(B,A);
			dig=dig*p%mo*dig%mo;
		}
		
		A=powmat((R-L)/24,A);
		ret=(ret*A.v[0][0]+L%mo*A.v[0][1]+A.v[0][2])%mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
